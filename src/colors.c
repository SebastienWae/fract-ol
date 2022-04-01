/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/01 16:34:50 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	i_to_color(int nb)
{
	int	color_palette[5];

	color_palette[0] = 0x00FF9500;
	color_palette[1] = 0x00FF0000;
	color_palette[2] = 0x00FF00F3;
	color_palette[3] = 0x00AA00FF;
	color_palette[4] = 0x00002EFF;
	if (nb > MAX_ITERATION / 5 * 4)
		return (color_palette[4]);
	else if (nb > MAX_ITERATION / 5 * 3)
		return (color_palette[3]);
	else if (nb > MAX_ITERATION / 5 * 2)
		return (color_palette[2]);
	else if (nb > MAX_ITERATION / 5 * 1)
		return (color_palette[1]);
	else
		return (color_palette[0]);
}
