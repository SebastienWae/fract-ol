/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 20:05:31 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

int	min(int a, int b)
{
	return (a < b ? a : b);
}

/**
 * @brief convert a coord to a complex number
 * 
 * @param coord 
 * @param state 
 * @return t_complex 
 */
t_complex	coord_to_cplx(t_coord coord, t_state *state)
{
	t_complex	cmplx;
	double		r_max = 2.0 * state->zoom;
	double		r_min = -2.0 * state->zoom;
	double		i_max = 2.0 * state->zoom;
	double		i_min = -2.0 * state->zoom;

	cmplx.r = r_min + (coord.x - 100) * (r_max - r_min) / min(WIDTH, HEIGHT);
	cmplx.i = i_min + coord.y * (i_max - i_min) / min(WIDTH, HEIGHT);
	return (cmplx);
}

/**
 * @brief convert a complex number to a coord
 * 
 * @param cplx 
 * @param state 
 * @return t_coord 
 */
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
