/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/31 12:02:43 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	close_window(t_state *state)
{
	mlx_destroy_window(state->mlx, state->win);
	state->mlx = NULL;
	return (0);
}

int	main(void)
{
	t_state	state;

	state = init_state(mandelbrot_set_to_img);
	update_img(&state, state.f);
	mlx_mouse_hook(state.win, mouse_button_hook, &state);
	mlx_hook(state.win, ON_DESTROY, 0, close_window, &state);
	mlx_loop_hook(state.mlx, render_next_frame_hook, &state);
	mlx_loop(state.mlx);
}
