/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:18 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 10:43:51 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

/**
 * @brief handle mouse events
 * 
 * @param button	button id
 * @param x			x coordinate
 * @param y			y coordinate
 * @param param		state
 * @return int 
 */
int	mouse_handler(int button, int x, int y, void *param)
{
	t_state	*s;

	(void)x;
	(void)y;
	s = (t_state *)param;
	if (button == SCROLL_DOWN)
		zoom(ZOOM_IN, s);
	else if (button == SCROLL_UP)
		zoom(ZOOM_OUT, s);
	return (0);
}

/**
 * @brief handle key events
 * 
 * @param keycode	key id
 * @param param		state
 * @return int 
 */
int	key_handler(int keycode, void *param)
{
	t_state	*s;

	s = (t_state *)param;
	if (keycode == KEY_ESC)
		quit(s);
	else if (keycode == KEY_PLUS)
		zoom(ZOOM_IN, s);
	else if (keycode == KEY_MINUS)
		zoom(ZOOM_OUT, s);
	else if (keycode == KEY_LEFT)
		s->offset.r += 0.01;
	else if (keycode == KEY_RIGHT)
		s->offset.r -= 0.01;
	else if (keycode == KEY_UP)
		s->offset.i += 0.01;
	else if (keycode == KEY_DOWN)
		s->offset.i -= 0.01;
	else if (keycode == KEY_RETURN)
	{
		s->offset.r = 0.5;
		s->offset.i = 0;
		zoom(ZOOM_RESET, s);
	}
	s->redraw = 1;
	return (0);
}

/**
 * @brief handle loop ticks
 * 
 * @param param	state
 * @return int 
 */
int	loop_handler(void *param)
{
	t_state		*s;

	s = (t_state *)param;
	if (s->mlx)
	{
		s->loops++;
		if (s->redraw)
		{
			s->render_func(s);
			s->redraw = 0;
			mlx_put_image_to_window(s->mlx, s->win, s->img->img, 0, 0);
		}
		else if (s->loops == 100)
		{
			s->color_scale++;
			s->redraw = 1;
			s->loops = 0;
		}
	}
	return (0);
}
