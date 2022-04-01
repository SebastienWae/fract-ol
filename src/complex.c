/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 11:23:31 by seb              ###   ########.fr       */
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
t_complex	coord_to_cplx(t_coord coord, double scale)
{
	int			offset;
	t_complex	cmplx;

	if (WIDTH > HEIGHT)
	{
		offset = (WIDTH - HEIGHT) / 2;
		cmplx.r = -scale + (coord.x - offset) * (scale * 2) / HEIGHT;
		cmplx.i = (-scale + coord.y * (scale * 2) / HEIGHT) * -1;
	}
	else
	{
		offset = (HEIGHT - WIDTH) / 2;
		cmplx.r = -scale + coord.x * (scale * 2) / WIDTH;
		cmplx.i = (-scale + (coord.y - offset) * (scale * 2) / WIDTH) * -1;
	}
	return (cmplx);
}

/**
 * @brief convert a complex number to a coordinate
 * 
 * @param cplx
 * @param scale 
 * @return t_coord 
 */
t_coord	cplx_to_coord(t_complex cplx, double scale)
{
	int			offset;
	t_coord		coord;

	if (WIDTH > HEIGHT)
	{
		offset = (WIDTH - HEIGHT) / 2;
		coord.x = offset + (cplx.r + scale) * HEIGHT / (scale * 2);
		coord.y = (cplx.i * -1 + scale) * HEIGHT / (scale * 2);
	}
	else
	{
		offset = (HEIGHT - WIDTH) / 2;
		coord.x = (cplx.r + scale) * WIDTH / (scale * 2);
		coord.y = offset + (cplx.i * -1 + scale) * WIDTH / (scale * 2);
	}
	return (coord);
}
