/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 15:47:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	linear_interpol(double a, double b, double t)
{
	return (a * (1 - t) + b * t);
}

t_complex	coord_to_cplx(t_coord coord, t_state *state)
{
	t_complex	cmplx;

	double	r_max = 2.0 * state->zoom;
	double	r_min = -2.0 * state->zoom;
	double	i_max = 2.0 * state->zoom;
	double	i_min = -2.0 * state->zoom;
	cmplx.r = r_min + (coord.x - 100)  * (r_max - r_min) / min(WIDTH, HEIGHT);
	cmplx.i = i_min + coord.y * (i_max - i_min) / min(WIDTH, HEIGHT);

	return (cmplx);
}

t_coord	cplx_to_coord(t_complex cplx, t_state *state)
{
	t_coord		coord;
	double		r_max = 2.0 * state->zoom;
	double		r_min = -2.0 * state->zoom;
	double		i_max = 2.0 * state->zoom;
	double		i_min = -2.0 * state->zoom;

	coord.x = 100 + (cplx.r - r_min) * min(WIDTH, HEIGHT) / (r_max - r_min);
	coord.y = (cplx.i - i_min) * min(WIDTH, HEIGHT) / (i_max - i_min);
	return (coord);
}
