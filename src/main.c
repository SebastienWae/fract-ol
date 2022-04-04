/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/04 13:45:23 by swaegene         ###   ########.fr       */
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
	t_args	args;
	t_state	s;

	args = parse_args(argc, argv);
	if (args.f)
	{
		s = init_state(&args);
		mlx_hook(s.win, ON_DESTROY, 0, quit, &s);
		mlx_mouse_hook(s.win, mouse_handler, &s);
		mlx_key_hook(s.win, key_handler, &s);
		mlx_loop_hook(s.mlx, loop_handler, &s);
		mlx_loop(s.mlx);
		return (0);
	}
	else
	{
		display_params();
		return (1);
	}
}
