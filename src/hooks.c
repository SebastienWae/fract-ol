/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:18 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 20:00:20 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	mouse_handler(int button, int x, int y, void *param)
{
	t_state	*state;

	(void)x;
	(void)y;
	state = (t_state *)param;
	if (button == SCROLL_DOWN)
		state->zoom -= .1;
	if (button == SCROLL_UP)
		state->zoom += .1;
	if (button == SCROLL_DOWN || button == SCROLL_UP)
	{
		state->outdated = 1;
	}
	return (0);
}

int	key_handler(int keycode, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (keycode == KEY_D)
	{
		state->debug = !state->debug;
		state->outdated = 1;
	}
	else if (keycode == KEY_ESC)
		quit(state);
	return (0);
}

int	loop_handler(void *param)
{
	t_state		*state;

	state = (t_state *)param;
	if (state->mlx)
	{
		if (state->outdated)
		{
			state->f(state, state->img);
			state->outdated = 0;
			if (!state->debug)
				mlx_put_image_to_window(state->mlx, state->win, state->img->img,
					0, 0);
		}
		if (state->debug)
			display_debug_info(state);
	}
	return (0);
}
