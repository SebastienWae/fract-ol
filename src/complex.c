/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/02 11:58:08 by seb              ###   ########.fr       */
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
t_complex	coord_to_cplx(t_coord coord, t_state *s)
{
	t_complex	cplx;

	cplx.r = (-SCALE + coord.x * s->factor.r) / s->zoom - s->offset.r;
	cplx.i = (-SCALE + coord.y * s->factor.i) / s->zoom - s->offset.i;
	return (cplx);
}
