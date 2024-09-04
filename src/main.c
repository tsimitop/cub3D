/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:31:46 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/07/23 19:09:59 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

/*
	\     \   /     /	
	 \  0-------#  /	0-------#0-------#0-------#
	  \ |   N   | /		|   N   ||   N   ||   N   |
	   X| W   E |X		| W   E || W   E || W   E |
	  / |   S   | \		|   S   ||   S   ||   S   |
	 /  #-------#  \	#-------##-------##-------#
	/     /   \     \	
	0 -> coordinate in map
	/ or \ -> incoming rays

	from different ray incomig angles different sides should be hit and tracked
	e.g. from south east walls should compare against coordinate + 1 in either
	direction

	check intersection only at raylengths where a wall could be
	-> find a vectorlength for the neares horizontal and neares vertical and
	from there on iterate in steps
*/

void	toggle_map(mlx_key_data_t key, t_var *data)
{
	if (data->config.map_opacity == 0)
		redraw_minimap(data);
	else
	{
		data->config.map_opacity = 0;
		ft_memset(data->map_render_img->pixels, 0, \
			data->map_render_img->width * \
			data->map_render_img->height * sizeof(int));
		ft_memset(data->map_layout_img->pixels, 0, \
			data->map_layout_img->width * \
			data->map_layout_img->height * sizeof(int));
	}
}

void	toggle_key_hook(mlx_key_data_t key, t_var *data)
{
	if (key.action == 1)
	{
		if (key.key == MLX_KEY_M)
			toggle_map(key, data);
		else if (key.key == MLX_KEY_G)
		{
			data->settings = !data->settings;
			if (data->settings)
				print_setting(data);
		}
		else if (key.key == MLX_KEY_SPACE)
			toggle_doors(key, data);
	}
}

void	press_hook(mlx_key_data_t key, void *param)
{
	t_var	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		data->shutdown = true;
		mlx_close_window(data->_mlx);
		return ;
	}
	else if (key.action && (key.key == MLX_KEY_LEFT \
							|| key.key == MLX_KEY_RIGHT))
	{
		if (key.key == MLX_KEY_LEFT)
			turn(data, LEFT);
		if (key.key == MLX_KEY_RIGHT)
			turn(data, RIGHT);
	}
	else if (key.action && key.key == MLX_KEY_V)
		mouse_action(data);
	else
		toggle_key_hook(key, data);
}

int	minimap(t_var *data)
{
	data->map_layout_img = mlx_new_image(data->_mlx, (data->map_width * \
					data->config.zoom), (data->map_height * data->config.zoom));
	data->map_render_img = mlx_new_image(data->_mlx, (data->map_width * \
					data->config.zoom), (data->map_height * data->config.zoom));
	mlx_image_to_window(data->_mlx, data->map_layout_img, 0, 0);
	mlx_image_to_window(data->_mlx, data->map_render_img, 0, 0);
	zoom_setting(0, 0, data);
	return (0);
}

void	lal(void)
{
	system("leaks cub3D");
}

int32_t	main(int argc, char **argv)
{
	t_var	data;

	atexit(lal);
	init(&data);
	*proto_global() = &data;
	if (parse_input(argc, argv, &data))
	{
		ft_printf(R1"parsing issues\n"QUIT_COLOR);
		exit (42);
	}
	print_data(&data);
	minimap(&data);
	floor_ceiling(&data);
	mlx_loop_hook(data._mlx, &loop_hook, &data);
	mlx_scroll_hook(data._mlx, &scroll_hook, &data);
	mlx_key_hook(data._mlx, &press_hook, &data);
	mlx_cursor_hook(data._mlx, &cursor_hook, &data);
	mlx_loop(data._mlx);
	free_data(&data);
	mlx_terminate(data._mlx);
	return (EXIT_SUCCESS);
}
