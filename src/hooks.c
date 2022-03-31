/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:18 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 14:11:46 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	mouse_button_hook(int button, int x, int y, void *param)
{
	t_state	*state;

	(void)x;
	(void)y;
	state = (t_state*)param;
	if (button == SCROLL_DOWN)
		state->zoom -= .1;
	if (button == SCROLL_UP)
		state->zoom += .1;
	if (button == SCROLL_DOWN || button == SCROLL_UP)
	{
		state->outdated = 1;
	}
	return (0);
}

//TODO: remove
#include <stdio.h>
int	mouse_move_hook(int x, int y, void *param)
{
	t_state		*state;
	t_coord		coord;
	t_complex	cplx;
	char	x_str[50];
	char	y_str[50];
	char	r_str[50];
	char	i_str[50];

	state = (t_state*)param;
	coord.x = x;
	coord.y = y;
	cplx = coord_to_cplx(coord, state);
	sprintf(x_str,"x: %d", coord.x);
	sprintf(y_str,"y: %d", coord.y);
	sprintf(r_str,"r: %f", cplx.r);
	sprintf(i_str,"i: %f", cplx.i);
	mlx_string_put(state->mlx, state->win, 15, 15, 0x0000FF00, x_str);
	mlx_string_put(state->mlx, state->win, 15, 30, 0x0000FF00, y_str);
	mlx_string_put(state->mlx, state->win, 15, 45, 0x0000FF00, r_str);
	mlx_string_put(state->mlx, state->win, 15, 60, 0x0000FF00, i_str);
	return (0);
}

int	render_next_frame_hook(void *param)
{
	t_state		*state;
	int			x;	
	int			y;	

	state = (t_state*)param;
	if (state->mlx)
	{
		if (state->outdated)
		{
			//update_img(state, state->f);
			state->f(state, state->img);
			argand_diagram_to_img(state, state->img);
			state->outdated = 0;
		}
		mlx_put_image_to_window(state->mlx, state->win, state->img->img, 0, 0);
		mlx_mouse_get_pos(state->win, &x, &y);
		mouse_move_hook(x, y, param);
	}
	return (0);
}
