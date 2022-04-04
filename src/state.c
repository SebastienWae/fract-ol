/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 10:45:37 by seb              ###   ########.fr       */
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

	s.zoom = 1;
	s.scale = 1;
	s.offset.r = 0.;
	s.offset.i = 0.;
	s.factor.r = (SCALE * 2) / HEIGHT;
	s.factor.i = (SCALE * 2) / WIDTH;
	s.c = args->c;
	s.color_scale = 0;
	s.loops = 0;
	s.redraw = 1;
	s.render_func = args->render_func;
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "fract-ol");
	s.img = new_image(s.mlx);
	return (s);
}
