/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:36:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/01 17:39:35 by swaegene         ###   ########.fr       */
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
void	zoom(enum e_zoom_dir dir, t_state *state)
{
	t_coord		mouse;
	t_complex	cplx;
	double		logMinZoom;
	double		logMaxZoom;
	double		logZoom;
	double		zoom;

	mlx_mouse_get_pos(state->win, &(mouse.x), &(mouse.y));
	cplx = coord_to_cplx(mouse, state);
	if (dir == ZOOM_IN)
	{
		state->step++;
		state->offset.r = cplx.r * -1;
		state->offset.i = cplx.i * -1;
	}
	else if (dir == ZOOM_OUT && state->zoom > 1)
		state->step--;
	logMinZoom = log(1.0);
	logMaxZoom = log(MAXFLOAT);
	logZoom = logMinZoom + (logMaxZoom - logMinZoom) * state->step / (500 - 1);
	zoom = exp(logZoom);
	state->zoom = zoom;
	state->redraw = 1;
}
