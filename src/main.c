/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/31 11:06:24 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	main(void)
{
	t_state	state;

	//state = init_state(argand_diagram_to_img);
	state = init_state(mandelbrot_set_to_img);
	update_img(&state, state.f);
	mlx_mouse_hook(state.win, mouse_button_hook, &state);
	mlx_hook(state.win, ON_MOUSEMOVE,  1L<<6, mouse_move_hook, &state);
	mlx_loop(state.mlx);
}
