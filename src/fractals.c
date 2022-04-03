/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/03 14:44:21 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdlib.h>
#include <math.h>

void	render_mandelbrot_set(t_state *s)
{
	double		tmp_z_r;
	t_coord		coord;
	t_complex	c;
	t_complex	z;
	int			iter;

	int			r1;
	int			r2;
	int			r3;

	r1 = rand() % 8;
	r2 = rand() % 8;
	r3 = rand() % 8;
	coord.x = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			c = coord_to_cplx(coord, s);
			z.r = 0;
			z.i = 0;
			iter = 0;
			while (z.r * z.r + z.i * z.i <= (SCALE * 2) && iter < MAX_ITERATION)
			{
				tmp_z_r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.r * z.i + c.i;
				z.r = tmp_z_r;
				iter++;
			}
			if (iter < MAX_ITERATION)
				put_pixel(s->img, coord, i_to_color(iter, z.r * z.r + z.i * z.i, s));
			else
				put_pixel(s->img, coord, 0x00000000);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}

void	render_julia_set(t_state *s)
{
	double		tmp_z_r;
	t_coord		coord;
	t_complex	z;
	int			iter;

	int			r1;
	int			r2;
	int			r3;

	r1 = rand() % 8;
	r2 = rand() % 8;
	r3 = rand() % 8;
	coord.x = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			z = coord_to_cplx(coord, s);
			iter = 0;
			while (z.r * z.r + z.i * z.i <= (SCALE * 2) && iter < MAX_ITERATION)
			{
				tmp_z_r = z.r * z.r - z.i * z.i + s->c.r;
				z.i = 2 * z.r * z.i + s->c.i;
				z.r = tmp_z_r;
				iter++;
			}
			if (iter < MAX_ITERATION)
				put_pixel(s->img, coord, i_to_color(iter, z.r * z.r + z.i * z.i, s));
			else
				put_pixel(s->img, coord, 0x00000000);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}

void	render_newton_set(t_state *s)
{
	double		tmp;
	t_coord		coord;
	t_complex	z;
	t_complex	old_z;
	int			iter;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		while (coord.y < HEIGHT)
		{
			z = coord_to_cplx(coord, s);
			tmp = 1.0;
			iter = 0;
			while (tmp > 0.000001 && iter < MAX_ITERATION)
			{
				old_z = z;
				tmp = (z.r * z.r + z.i * z.i) * (z.r * z.r + z.i * z.i);
				z.r = (2 * z.r * tmp + z.r * z.r - z.i * z.i) / (3.0 * tmp);
				z.i = (2 * z.i * (tmp - old_z.r)) / (3.0 * tmp);
				tmp = (z.r - old_z.r) * (z.r - old_z.r) + (z.i - old_z.i) * (z.i - old_z.i);
				iter++;
			}
			if (iter < MAX_ITERATION)
				put_pixel(s->img, coord, i_to_color(iter, z.r * z.r + z.i * z.i, s));
			else
				put_pixel(s->img, coord, 0x00000000);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}
