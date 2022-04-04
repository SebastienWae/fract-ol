/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:30:36 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 09:56:05 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ft_printf.h>
#include <libft.h>

static double	ft_atof(const char *str)
{
	int		sign;
	double	right;
	double	left;
	int		e;

	left = 0;
	right = 0.0;
	sign = 1;
	e = 1;
	if (ft_strchr(str, '.') == 0)
		return (ft_atoi(str));
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		left = left * 10 + *str++ - '0';
	str++;
	while (ft_isdigit(*str))
	{
		right = right * 10 + *str++ - '0';
		e *= 10;
	}
	return (sign * ((double)left + (double)right / e));
}

t_args	parse_args(int argv, char **argc)
{
	t_args	args;

	if (argv == 2)
	{
		if (ft_strncmp(argc[1], "mandelbrot", ft_strlen(argc[1])) == 0)
			args.render_func = render_mandelbrot_set;
		else if (ft_strncmp(argc[1], "newton", ft_strlen(argc[1])) == 0)
			args.render_func = render_newton_set;
		else
			args.render_func = NULL;
	}
	else if (argv == 4
		&& ft_strncmp(argc[1], "julia", ft_strlen(argc[1])) == 0)
	{
		args.render_func = render_julia_set;
		args.c.r = ft_atof(argc[2]);
		args.c.i = ft_atof(argc[3]);
	}
	else
		args.render_func = NULL;
	return (args);
}

void	display_params(void)
{
	ft_printf("USAGE: fractol <fractal> [<args>]\n\n");
	ft_printf("FRACTALS:\n");
	ft_printf("	mandelbrot\n");
	ft_printf("	julia <c real> <c imaginary>\n");
	ft_printf("	newton\n");
}
