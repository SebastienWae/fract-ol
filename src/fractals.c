/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:16:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 14:48:24 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>
#include <mlx.h>

void	build_fractal(t_state *s)
{
	t_coord	coord;
	t_pixel	pixel;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			pixel = s->fractal->f(coord_to_cplx(coord, s), s);
			s->fractal->pixels[coord.x][coord.y] = pixel;
			coord.y++;
		}
		coord.x++;
	}
}

void	render_fractal(t_state *s)
{
	t_coord			coord;
	unsigned int	color;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		while (coord.y < HEIGHT)
		{
			color = i_to_color(s->fractal->pixels[coord.x][coord.y].iter,
					s->fractal->pixels[coord.x][coord.y].sqr,
					s);
			put_pixel(s->img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img->img, 0, 0);
}

t_pixel	mandelbrot(t_complex c, t_state *s)
{
	double		tmp_z_r;
	t_complex	z;
	t_pixel		pixel;

	(void)s;
	pixel.iter = 0;
	pixel.sqr = 0;
	z = (t_complex){0, 0};
	while (z.r * z.r + z.i * z.i <= (SCALE * 2) && pixel.iter < MAX_ITERATION)
	{
		tmp_z_r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = tmp_z_r;
		pixel.iter++;
	}
	pixel.sqr = z.r * z.r + z.i * z.i;
	return (pixel);
}

t_pixel	julia(t_complex z, t_state *s)
{
	double		tmp_z_r;
	t_pixel		pixel;

	pixel.iter = 0;
	pixel.sqr = 0;
	while (z.r * z.r + z.i * z.i <= (SCALE * 2) && pixel.iter < MAX_ITERATION)
	{
		tmp_z_r = z.r * z.r - z.i * z.i + s->c.r;
		z.i = 2 * z.r * z.i + s->c.i;
		z.r = tmp_z_r;
		pixel.iter++;
	}
	pixel.sqr = z.r * z.r + z.i * z.i;
	return (pixel);
}

t_pixel	newton(t_complex z, t_state *s)
{
	double		t;
	t_complex	tz;
	t_pixel		pixel;

	(void)s;
	pixel.iter = 0;
	pixel.sqr = 0;
	t = 1.;
	while (t > 0.000001 && pixel.iter < MAX_ITERATION)
	{
		tz = z;
		t = (z.r * z.r + z.i * z.i) * (z.r * z.r + z.i * z.i);
		z.r = (2 * z.r * t + z.r * z.r - z.i * z.i) / (3.0 * t);
		z.i = (2 * z.i * (t - tz.r)) / (3.0 * t);
		t = (z.r - tz.r) * (z.r - tz.r) + (z.i - tz.i) * (z.i - tz.i);
		pixel.iter++;
	}
	pixel.sqr = z.r * z.r + z.i * z.i;
	return (pixel);
}
