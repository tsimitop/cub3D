#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub.h"

enum e_textures {
	north,
	south,
	west,
	east,
	door
};

typedef struct s_ray
{
	int				number;
	double			x;
	double			y;
	double			wall_dst;
	double			wall_percent;
	mlx_texture_t	*wall;
}	t_ray;

typedef struct s_intvctr
{
	int	y;
	int	x;
}	t_intvctr;

typedef struct s_draw_ray
{
	int			i;
	vec2d_t		s_dist;
	vec2d_t		d_dist;
	vec2d_t		step;
	vec2d_t		map;
	int			side;
	int			color;
	t_ray		*ray;
	char		hit;
}	t_draw_ray;

typedef struct s_var
{
	mlx_t			*_mlx;

	t_config		config;
	bool			shutdown;

	t_list			*text;
	mlx_image_t		*map_layout_img;
	mlx_image_t		*map_render_img;
	mlx_image_t		*main_static_img;
	mlx_image_t		*main_render_img;

	char			*path_north;
	char			*path_south;
	char			*path_westh;
	char			*path_easth;
	char			*path_door;

	mlx_texture_t	*textures[5];
	gd_GIF			*gif[5];
	bool			has_door;

	int32_t			floor;
	int32_t			ceiling;

	char			**map;
	int				map_width;
	int				map_height;

	vec2d_t			player;
	vec2d_t			direct;
	vec2d_t			move;

	t_ray			*rays;

	int				settings;

	struct timeval	time;

	int				mouse;
}	t_var;

#endif