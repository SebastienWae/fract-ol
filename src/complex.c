/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 14:24:46 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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

	cplx.r = (-SCALE + coord.x * s->factor.r) / s->scale - s->offset.r;
	cplx.i = (-SCALE + coord.y * s->factor.i) / s->scale - s->offset.i;
	return (cplx);
}
