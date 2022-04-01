/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 16:20:39 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

/**
 * @brief convert a coordinate to a complex number
 * 
 * @param coord 
 * @param scale 
 * @return t_complex 
 */
t_complex	coord_to_cplx(t_coord coord, t_state *state)
{
	double		r_offset;
	double		i_offset;
	t_complex	cplx;

	if (WIDTH > HEIGHT)
	{
		r_offset = (WIDTH - HEIGHT) / 2 + state->offset.r;
		i_offset = state->offset.i;
	}
	else
	{
		r_offset = state->offset.r;
		i_offset = (HEIGHT - WIDTH) / 2 + state->offset.i;
	}
	cplx.r = (-SCALE + coord.x * (SCALE * 2) / HEIGHT) / state->zoom - r_offset;
	cplx.i = (-SCALE + coord.y * (SCALE * 2) / WIDTH) / state->zoom - i_offset;
	return (cplx);
}

/**
 * @brief convert a complex number to a coordinate
 * 
 * @param cplx
 * @param scale 
 * @return t_coord 
 */
t_coord	cplx_to_coord(t_complex cplx, t_state *state)
{
	double		r_offset;
	double		i_offset;
	t_coord		coord;

	if (WIDTH > HEIGHT)
	{
		r_offset = (WIDTH - HEIGHT) / 2 + state->offset.r;
		i_offset = state->offset.i;
	}
	else
	{
		r_offset = state->offset.r;
		i_offset = (HEIGHT - WIDTH) / 2 + state->offset.i;
	}
	coord.x = ((cplx.r + r_offset) * state->zoom + SCALE) * HEIGHT / (SCALE * 2);
	coord.y = ((cplx.i + i_offset) * state->zoom + SCALE) * WIDTH / (SCALE * 2);
	return (coord);
}
