/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/02 11:59:10 by seb              ###   ########.fr       */
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
int	quit(t_state *s)
{
	destroy_state(s);
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
	t_state	s;

	(void)argc;
	(void)argv;
	s = init_state(render_mandelbrot_set);
	mlx_hook(s.win, ON_DESTROY, 0, quit, &s);
	mlx_mouse_hook(s.win, mouse_handler, &s);
	mlx_key_hook(s.win, key_handler, &s);
	mlx_loop_hook(s.mlx, loop_handler, &s);
	mlx_loop(s.mlx);
}
