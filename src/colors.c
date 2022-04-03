/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/03 14:19:50 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

unsigned int	i_to_color(int iterations, double n, t_state *s)
{
	double			continuous_index;
	unsigned char	c[4];

	//(void)s;
	(void)n;
	continuous_index = iterations + 1 - (log(2) / n) / log (2);
	//continuous_index = iterations + 1;
	c[0] = (unsigned char)(sin(s->freq * continuous_index + 4) * 230 + 25);
	c[1] = (unsigned char)(sin(s->freq * continuous_index + 2) * 230 + 25);
	c[2] = (unsigned char)(sin(s->freq * continuous_index + 0) * 230 + 25);
	c[3] = 0;
	return (*(unsigned int *)c);
}
