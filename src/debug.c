/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:32 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 11:09:46 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

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
			my_mlx_pixel_put(img, coord.x + i, coord.y + j, 0x0000FF00);
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
				my_mlx_pixel_put(img, coord.x, coord.y, 0x00FF0000);
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
