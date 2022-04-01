/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/01 15:03:38 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

/**
 * @brief free allocated memory and quit the program
 * 
 * @param state 
 * @return int 
 */
int	quit(t_state *state)
{
	destroy_state(state);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * @brief entry point of the program
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_state	state;

	(void)argc;
	(void)argv;
	state = init_state(render_mandelbrot_set);
	mlx_hook(state.win, ON_DESTROY, 0, quit, &state);
	mlx_mouse_hook(state.win, mouse_handler, &state);
	mlx_key_hook(state.win, key_handler, &state);
	mlx_loop_hook(state.mlx, loop_handler, &state);
	mlx_loop(state.mlx);
}
