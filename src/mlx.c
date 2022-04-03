/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:20:12 by seb               #+#    #+#             */
/*   Updated: 2022/04/02 14:07:24 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

/**
 * @brief put pixel in image img at coord (x, y) with color c
 * 
 * @param img
 * @param coord
 * @param c	color in format 0xAARRGGBB
 */
void	put_pixel(t_img *img, t_coord coord, unsigned int c)
{
	char	*dst;

	dst = img->addr + (coord.y * img->line_length + coord.x * (img->bpp / 8));
	*(unsigned int *)dst = c;
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
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_length), &(img->endian));
	return (img);
}
