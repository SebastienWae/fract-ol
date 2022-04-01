/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 10:36:44 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	render_mandelbrot_set(t_state *state)
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
			c = coord_to_cplx(coord, 2 * state->zoom);
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
				put_pixel(state->img, coord, 0x00FFFFFF);
			else
				put_pixel(state->img, coord, iter);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}
