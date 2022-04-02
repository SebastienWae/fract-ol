/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:36:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/02 11:59:41 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <math.h>

/**
 * @brief zoom in or out
 * 
 * @param dir 	zooming direction
 * @param state 
 */
void	zoom(enum e_zoom_dir dir, t_state *s)
{
	t_coord		mouse;
	t_complex	cplx;
	t_complex	cplx2;
	double		logMinZoom;
	double		logMaxZoom;
	double		logZoom;
	double		zoom;

	mlx_mouse_get_pos(s->win, &(mouse.x), &(mouse.y));
	cplx = coord_to_cplx(mouse, s);
	if (dir == ZOOM_IN)
		s->step++;
	else if (dir == ZOOM_OUT && s->zoom > 1)
		s->step--;
	else if (dir == ZOOM_RESET)
		s->step = 0;
	logMinZoom = log(1.0);
	logMaxZoom = log(MAXFLOAT);
	logZoom = logMinZoom + (logMaxZoom - logMinZoom) * s->step / (MAX_STEPS - 1);
	zoom = exp(logZoom);
	s->zoom = zoom;
	cplx2 = coord_to_cplx(mouse, s);
	if (dir == ZOOM_IN)
	{
		s->offset.r += (cplx2.r - cplx.r);
		s->offset.i += (cplx2.i - cplx.i);
	}
	s->redraw = 1;
}
