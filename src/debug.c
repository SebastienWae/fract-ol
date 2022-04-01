/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:32 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 13:24:15 by swaegene         ###   ########.fr       */
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
	char		x_str[50];
	char		y_str[50];
	char		r_str[50];
	char		i_str[50];
	char		zoom[50];
	char		x_offset[50];
	char		y_offset[50];

	display_argand_diagram(state);
	draw_rectangle(state->img, (t_coord){0, 0}, (t_coord){110, 115}, 0x0000FF00);

#ifdef __linux__
	mlx_mouse_get_pos(state->mlx, state->win, &(mouse.x), &(mouse.y));
#endif
#ifdef __APPLE__
	mlx_mouse_get_pos(state->win, &(mouse.x), &(mouse.y));
#endif
	cplx = coord_to_cplx(mouse, 2 * state->zoom);
	sprintf(x_str, "x: %d", mouse.x);
	sprintf(y_str, "y: %d", mouse.y);
	sprintf(r_str, "r: %f", cplx.r);
	sprintf(i_str, "i: %f", cplx.i);
	sprintf(zoom, "zoom: %f", state->zoom);
	sprintf(x_offset, "x offset: %d", state->offset.x);
	sprintf(y_offset, "y offset: %d", state->offset.y);

	mlx_put_image_to_window(state->mlx, state->win, state->img->img, 0, 0);

	mlx_string_put(state->mlx, state->win, 15, 15, 0x00000000, x_str);
	mlx_string_put(state->mlx, state->win, 15, 30, 0x00000000, y_str);
	mlx_string_put(state->mlx, state->win, 15, 45, 0x00000000, r_str);
	mlx_string_put(state->mlx, state->win, 15, 60, 0x00000000, i_str);
	mlx_string_put(state->mlx, state->win, 15, 75, 0x00000000, zoom);
	mlx_string_put(state->mlx, state->win, 15, 90, 0x00000000, x_offset);
	mlx_string_put(state->mlx, state->win, 15, 105, 0x00000000, y_offset);
}

void	display_argand_diagram(t_state *state)
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
			cplx = coord_to_cplx(coord, 2 * state->zoom);
			if (cplx.r == 0 || cplx.i == 0)
			{
				put_pixel(state->img, coord, 0x00FF0000);
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
		coord = cplx_to_coord(cplx, 2 * state->zoom);
		if (coord.x >= 2 && coord.x < WIDTH && coord.y >= 2 && coord.y < HEIGHT)
			draw_rectangle(state->img, (t_coord){coord.x - 2, coord.y - 2},
				(t_coord){coord.x + 2, coord.y + 2}, 0x0000FF00);
		cplx.r = 0;
		cplx.i = i;
		coord = cplx_to_coord(cplx, 2 * state->zoom);
		if (coord.x >= 2 && coord.x < WIDTH && coord.y >= 2 && coord.y < HEIGHT)
			draw_rectangle(state->img, (t_coord){coord.x - 2, coord.y - 2},
				(t_coord){coord.x + 2, coord.y + 2}, 0x0000FF00);
		i++;
	}
}
