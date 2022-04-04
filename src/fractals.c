/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 11:06:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

static unsigned int	i_to_color(int iter, double n, t_state *s)
{
	double			value;
	unsigned char	c[4];

	if (iter < MAX_ITERATION)
	{
		value = iter + 1 - (log(2) / n) / log (2) + s->color_scale;
		c[0] = (unsigned char)(sin(0.1 * value + 0) * 128 + 127);
		c[1] = (unsigned char)(sin(0.2 * value + 2) * 128 + 127);
		c[2] = (unsigned char)(sin(0.3 * value + 4) * 128 + 127);
		c[3] = 0;
		return (*(unsigned int *)c);
	}
	else
		return (0);
}

void	draw_img(t_state *s)
{
	t_coord			coord;
	unsigned int	color;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			color = s->render_func(s, coord_to_cplx(coord, s));
			put_pixel(s->img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}

void	render_mandelbrot_set(t_state *s)
{
	double		tmp_z_r;
	t_coord		coord;
	t_complex	c;
	t_complex	z;
	double		sqr;
	int			i;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			c = coord_to_cplx(coord, s);
			z = (t_complex){0, 0};
			i = 0;
			sqr = 0;
			while (sqr <= (SCALE * 2) && ++i < MAX_ITERATION)
			{
				tmp_z_r = squared_cplx(z) + c.r;
				z.i = 2 * z.r * z.i + c.i;
				z.r = tmp_z_r;
				sqr = squared_cplx(z);
			}
			put_pixel(s->img, coord, i_to_color(i, sqr, s));
			coord.y++;
		}
		coord.x++;
	}
}

void	render_julia_set(t_state *s)
{
	double		tmp_z_r;
	t_coord		coord;
	t_complex	z;
	int			iter;

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
				put_pixel(s->img, coord, iter_to_color(iter, z.r * z.r + z.i * z.i, s));
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
				put_pixel(s->img, coord, iter_to_color(iter, z.r * z.r + z.i * z.i, s));
			else
				put_pixel(s->img, coord, 0x00000000);
			coord.y++;
		}
		coord.y = 0;
		coord.x++;
	}
}
