/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:32 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 17:28:51 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

//TODO: remove
#include <stdio.h>
void	display_debug_info(t_state *state)
{
	t_complex	cplx;
	t_coord		mouse;
	char	x_str[50];
	char	y_str[50];
	char	r_str[50];
	char	i_str[50];

	argand_diagram_to_img(state, state->img);
#ifdef __APPLE__
	mlx_mouse_get_pos(state->win, &x, &y);
#elif __linux__
	mlx_mouse_get_pos(state->mlx, state->win, &(mouse.x), &(mouse.y));
#endif
	cplx = coord_to_cplx(mouse, state);
	sprintf(x_str,"x: %d", mouse.x);
	sprintf(y_str,"y: %d", mouse.y);
	sprintf(r_str,"r: %f", cplx.r);
	sprintf(i_str,"i: %f", cplx.i);
	mlx_put_image_to_window(state->mlx, state->win, state->img->img, 0, 0);
	mlx_string_put(state->mlx, state->win, 15, 15, 0x0000FF00, x_str);
	mlx_string_put(state->mlx, state->win, 15, 30, 0x0000FF00, y_str);
	mlx_string_put(state->mlx, state->win, 15, 45, 0x0000FF00, r_str);
	mlx_string_put(state->mlx, state->win, 15, 60, 0x0000FF00, i_str);
}

void	draw_square(t_img *img, t_coord coord)
{
	int		i;
	int		j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			pixel_put(img, coord.x + i, coord.y + j, 0x0000FF00);
			j++;
		}
		i++;
	}
}

void	argand_diagram_to_img(t_state *state, t_img *img)
{
	t_coord		coord;
	t_complex	cplx;
	int			i;

	coord.x = 0;
	coord.y = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			cplx = coord_to_cplx(coord, state);
			if (cplx.r == 0 || cplx.i == 0)
			{
				pixel_put(img, coord.x, coord.y, 0x00FF0000);
			}
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
	i = -2;
	while (i <= 2)
	{
		cplx.r = i;
		cplx.i = 0;
		coord = cplx_to_coord(cplx, state);
		if (coord.x >= 2 && coord.x < WIDTH && coord.y >= 2 && coord.y < HEIGHT)
			draw_square(img, coord);
		cplx.r = 0;
		cplx.i = i;
		coord = cplx_to_coord(cplx, state);
		if (coord.x >= 2 && coord.x < WIDTH && coord.y >= 2 && coord.y < HEIGHT)
			draw_square(img, coord);
		i++;
	}
}
