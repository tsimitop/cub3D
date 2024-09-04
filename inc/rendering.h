#ifndef RENDERING_H
# define RENDERING_H

# include "cub.h"

// floor_ceiling
void	floor_ceiling(t_var *data);
// slicer
void	put_slice(t_var *data, int i);
void	render_view(t_var *data);
// doors
void	toggle_doors(mlx_key_data_t key, t_var *data);
int		check_door(int i, t_var *data);

void	draw_line_b(t_var *data, int height, int raynum);
void	gif_next_frame(gd_GIF *gif, mlx_texture_t *tex);
#endif