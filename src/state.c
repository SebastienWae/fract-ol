/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 17:36:49 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

/**
 * @brief destroy the state and free allocated memory
 * 
 * @param state 
 */
void	destroy_state(t_state *state)
{
	mlx_destroy_window(state->mlx, state->win);
	free(state->img);
}

/**
 * @brief initialize the state with the default values
 * 
 * @param f function to generate the image to display
 * @return t_state 
 */
t_state	init_state(t_render_func f)
{
	t_state	state;

	state.zoom = 1;
	state.step = 1;
	state.offset.r = 0.;
	state.offset.i = 0.;
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, WIDTH, HEIGHT, "fract-ol");
	state.img = new_image(state.mlx);
	state.render_func = f;
	state.redraw = 1;
	return (state);
}
