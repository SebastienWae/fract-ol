/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_alternate_form.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:22:19 by seb               #+#    #+#             */
/*   Updated: 2022/03/16 17:42:58 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_flags.h>

void	ft_parse_alternate_form(const char **f, t_f_flags *flags)
{
	(*f)++;
	flags->alternate_form = 1;
}