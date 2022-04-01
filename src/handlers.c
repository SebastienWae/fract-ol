/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:18 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 16:14:54 by swaegene         ###   ########.fr       */
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
	t_state	*state;

	(void)x;
	(void)y;
	state = (t_state *)param;
	if (button == SCROLL_DOWN)
		zoom(ZOOM_IN, state);
	else if (button == SCROLL_UP)
		zoom(ZOOM_OUT, state);
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
	t_state	*state;

	state = (t_state *)param;
	if (keycode == KEY_ESC)
		quit(state);
	else if (keycode == KEY_PLUS)
		zoom(ZOOM_IN, state);
	else if (keycode == KEY_MINUS)
		zoom(ZOOM_OUT, state);
	else if (keycode == KEY_LEFT)
		state->offset.r += 0.1;
	else if (keycode == KEY_RIGHT)
		state->offset.r -= 0.1;
	else if (keycode == KEY_UP)
		state->offset.i += 0.1;
	else if (keycode == KEY_DOWN)
		state->offset.i -= 0.1;
	if (keycode == KEY_DOWN || keycode == KEY_UP || keycode == KEY_LEFT || keycode == KEY_RIGHT)
		state->redraw = 1;
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
	t_state		*state;

	state = (t_state *)param;
	if (state->mlx)
	{
		if (state->redraw)
		{
			state->render_func(state);
			state->redraw = 0;
			//TODO: uncomment after display debug is remove
			//mlx_put_image_to_window(state->mlx, state->win, state->img->img, 0, 0);
		}
		display_debug_info(state);
	}
	return (0);
}
