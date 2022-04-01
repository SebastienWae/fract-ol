/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 09:43:19 by seb              ###   ########.fr       */
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
	state.offset.x = 0;
	state.offset.y = 0;
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, WIDTH, HEIGHT, "fract-ol");
	state.img = new_image(state.mlx);
	state.f = f;
	state.outdated = 1;
	return (state);
}
