/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:20:12 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 16:42:53 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

/**
 * @brief put pixel in image img at coord (x, y) with color c
 * 
 * @param img
 * @param x
 * @param y
 * @param c color in format 0xRRGGBB
 */
void	pixel_put(t_img *img, int x, int y, int c)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = c;
}

/**
 * @brief create a new image 
 * 
 * @param mlx 
 * @return t_img* 
 */
t_img	*new_image(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
								&(img->line_length), &(img->endian));
	return (img);
}
