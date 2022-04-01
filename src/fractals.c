/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 16:36:32 by swaegene         ###   ########.fr       */
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
			put_pixel(state->img, coord, i_to_color(iter));
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}
