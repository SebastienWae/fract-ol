/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 16:35:24 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mandelbrot_set_to_img(t_state *state, t_img *img)
{
	double		tmp_z_r;
	t_coord		coord;
	t_complex	c;
	t_complex	z;
	int			iter;

	coord.x = 0;
	coord.y = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			c = coord_to_cplx(coord, state);
			z.r = 0;
			z.i = 0;
			iter = 0;
			while (z.r * z.r + z.i * z.i < 4 && iter < MAX_ITERATION)
			{
				tmp_z_r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.r * z.i + c.i;
				z.r = tmp_z_r;
				iter++;
			}
			if (iter == MAX_ITERATION)
				pixel_put(img, coord.x, coord.y, 0x00FFFFFF);
			else
				pixel_put(img, coord.x, coord.y, iter);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}
