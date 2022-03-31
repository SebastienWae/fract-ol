/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:20:12 by seb               #+#    #+#             */
/*   Updated: 2022/03/30 22:30:46 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_img	*generate_new_image(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
								&(img->line_length), &(img->endian));
	return (img);
}

void	update_img(t_state *state, void (f)(t_state *, t_img *))
{
	t_img	*img;

	img = generate_new_image(state->mlx);
	f(state, img);
	mlx_put_image_to_window(state->mlx, state->win, img->img, 0, 0);
	if (state->img)
	{
		mlx_destroy_image(state->mlx, state->img->img);
		free(state->img);
	}
	state->img = img;
}