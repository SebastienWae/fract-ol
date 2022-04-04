/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 14:07:18 by swaegene         ###   ########.fr       */
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
	free(s->fractal);
}

t_fractal	*new_fractal(t_fractal_func f)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	fractal->f = f;
	return (fractal);
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
	s.render = 0;
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "fract-ol");
	s.img = new_image(s.mlx);
	s.fractal = new_fractal(args->f);
	return (s);
}
