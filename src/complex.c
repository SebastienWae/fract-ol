/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 10:52:10 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	coord_to_cplx(t_coord coord, t_state *state)
{
	t_complex	cmplx;

	cmplx.r = (coord.x - WIDTH / 2.) / (0.5 * state->zoom * min(WIDTH, HEIGHT));
	cmplx.i = (coord.y - HEIGHT / 2.) / (0.5 * state->zoom * min(WIDTH, HEIGHT));
	return (cmplx);
}

t_coord	cplx_to_coord(t_complex cplx, t_state *state)
{
	t_coord	coord;

	coord.x = (cplx.r * state->zoom * min(WIDTH, HEIGHT)) / 2. + WIDTH / 2.;
	coord.y = (cplx.i * state->zoom * min(WIDTH, HEIGHT)) / 2. + HEIGHT / 2.;
	return (coord);
}
