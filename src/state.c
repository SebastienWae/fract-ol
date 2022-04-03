/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/03 14:20:12 by seb              ###   ########.fr       */
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
void	destroy_state(t_state *s)
{
	mlx_destroy_window(s->mlx, s->win);
	free(s->img);
}

/**
 * @brief initialize the state with the default values
 * 
 * @param f function to generate the image to display
 * @return t_state 
 */
t_state	init_state(t_args *args)
{
	t_state	s;

	s.steps = 0;
	s.offset.r = 0.;
	s.offset.i = 0.;
	s.factor.r = (SCALE * 2) / HEIGHT;
	s.factor.i = (SCALE * 2) / WIDTH;
	s.frame = 0;
	s.freq = 0.;
	s.zoom = 1;
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "fract-ol");
	s.img = new_image(s.mlx);
	s.render_func = args->render_func;
	s.c = args->c;
	s.redraw = 1;
	return (s);
}
