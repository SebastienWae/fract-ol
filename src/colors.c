/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:44:21 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/04 13:44:37 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fractol.h>

unsigned int	i_to_color(int iter, double n, t_state *s)
{
	double			value;
	unsigned char	c[4];

	if (iter < MAX_ITERATION)
	{
		value = iter + 1 - (log(2) / n) / log (2) + s->color_scale;
		c[0] = (unsigned char)(sin(0.1 * value + 0) * 128 + 127);
		c[1] = (unsigned char)(sin(0.2 * value + 2) * 128 + 127);
		c[2] = (unsigned char)(sin(0.3 * value + 4) * 128 + 127);
		c[3] = 0;
		return (*(unsigned int *)c);
	}
	else
		return (0);
}
