/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:59 by seb               #+#    #+#             */
/*   Updated: 2022/03/30 22:25:22 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

t_state	init_state(void)
{
	t_state	state;

	state.img = NULL;
	state.zoom = 0.8;
	state.center.x = 0;
	state.center.y = 0;
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, WIDTH, HEIGHT, "fract-ol");
	return (state);
}
