/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:18 by seb               #+#    #+#             */
/*   Updated: 2022/03/30 22:23:40 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse_button_hook(int button, int x, int y, void *param)
{
	static int work;
	t_state	*state;

	(void)x;
	(void)y;
	state = (t_state*)param;
	if (button == SCROLL_DOWN)
		state->zoom += .2;
	if (button == SCROLL_UP)
		state->zoom -= .2;
	if (button == SCROLL_DOWN || button == SCROLL_UP)
	{
		if (!work)
		{
			work = 1;
			update_frame(state, mandelbrot_set_to_img);
			work = 0;
		}
	}
		//update_frame(state, agrand_diagram_to_img);
	return (0);
}
