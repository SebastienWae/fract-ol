/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:18:32 by seb               #+#    #+#             */
/*   Updated: 2022/03/30 22:19:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	agrand_diagram_to_img(t_state *state, t_img *img)
{
	t_coord		coord;
	t_complex	cplx;

	coord.x = 0;
	coord.y = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			cplx = coord_to_cplx(coord, state);
			if (cplx.r == 0 || cplx.i == 0)
				my_mlx_pixel_put(img, coord.x, coord.y, 0x00FFFFFF);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
	cplx.r = 0;
	cplx.i = 0;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = 1;
	cplx.i = 0;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = -1;
	cplx.i = 0;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = 0;
	cplx.i = 1;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = 0;
	cplx.i = -1;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = 2;
	cplx.i = 0;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
	cplx.r = 0;
	cplx.i = 2;
	coord = cplx_to_coord(cplx, state);
	if (coord.x < WIDTH && coord.y < HEIGHT)
	{
		my_mlx_pixel_put(img, coord.x - 2, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 2, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y - 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y - 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 1, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 1, 0x0000FF00);

		my_mlx_pixel_put(img, coord.x - 2, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x - 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 1, coord.y + 2, 0x0000FF00);
		my_mlx_pixel_put(img, coord.x + 2, coord.y + 2, 0x0000FF00);
	}
}
