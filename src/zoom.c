/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:36:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/04 10:46:32 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <math.h>

/**
 * @brief change zoom factor linearily
 * 
 * @param steps 
 * @return double 
 */
static double	zoom_interpolation(int steps)
{
	double		log_min;
	double		log_max;
	double		zoom;

	log_min = 1;
	log_max = log(MAXFLOAT);
	zoom = exp(log_min + (log_max - log_min) * steps / (MAX_STEPS - 1));
	return (zoom);
}

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

	if (dir == ZOOM_IN)
	{
		mlx_mouse_get_pos(s->win, &(mouse.x), &(mouse.y));
		cplx = coord_to_cplx(mouse, s);
		s->zoom++;
		s->scale = zoom_interpolation(s->zoom);
		cplx2 = coord_to_cplx(mouse, s);
		s->offset.r += (cplx2.r - cplx.r);
		s->offset.i += (cplx2.i - cplx.i);
	}
	else if (dir == ZOOM_OUT && s->zoom > 0)
	{
		s->zoom--;
		s->scale = zoom_interpolation(s->zoom);
	}
	else if (dir == ZOOM_RESET)
	{
		s->zoom = 1;
		s->scale = 1;
	}
	s->redraw = 1;
}
