/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:32 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 20:09:11 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

void	draw_square(t_img *img, t_coord coord, int size)
{
	int		i;
	int		j;

	i = -size;
	while (i <= size)
	{
		j = -size;
		while (j <= size)
		{
			put_pixel(img, coord.x + i, coord.y + j, 0x0000FF00);
			j++;
		}
		i++;
	}
}

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

	argand_diagram_to_img(state, state->img);
	mlx_mouse_get_pos(state->mlx, state->win, &(mouse.x), &(mouse.y));
	cplx = coord_to_cplx(mouse, state);
	sprintf(x_str, "x: %d", mouse.x);
	sprintf(y_str, "y: %d", mouse.y);
	sprintf(r_str, "r: %f", cplx.r);
	sprintf(i_str, "i: %f", cplx.i);
	draw_square(state->img, (t_coord){50, 50}, 50);
	mlx_put_image_to_window(state->mlx, state->win, state->img->img, 0, 0);
	mlx_string_put(state->mlx, state->win, 15, 15, 0x00000000, x_str);
	mlx_string_put(state->mlx, state->win, 15, 30, 0x00000000, y_str);
	mlx_string_put(state->mlx, state->win, 15, 45, 0x00000000, r_str);
	mlx_string_put(state->mlx, state->win, 15, 60, 0x00000000, i_str);
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
				put_pixel(img, coord.x, coord.y, 0x00FF0000);
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
			draw_square(img, coord, 2);
		cplx.r = 0;
		cplx.i = i;
		coord = cplx_to_coord(cplx, state);
		if (coord.x >= 2 && coord.x < WIDTH && coord.y >= 2 && coord.y < HEIGHT)
			draw_square(img, coord, 2);
		i++;
	}
}
