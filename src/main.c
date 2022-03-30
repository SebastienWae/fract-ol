/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:15 by swaegene          #+#    #+#             */
/*   Updated: 2022/03/30 22:30:49 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	main(void)
{
	t_state	state;

	state = init_state();
	update_img(&state, mandelbrot_set_to_img);
	mlx_mouse_hook(state.win, mouse_button_hook, &state);
	mlx_loop(state.mlx);
}
