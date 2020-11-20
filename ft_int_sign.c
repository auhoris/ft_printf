/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:48:26 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 12:41:52 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_sign(t_args *par, char *str)
{
	if (str[0] == '-')
	{
		par->sign = '-';
		str++;
	}
	else if (par->plus_f == ON)
		par->sign = '+';
	else if (par->space_f == ON)
		par->sign = ' ';
	return (str);
}

char	*ft_set_sign(t_args *par, char *filler, int str_len)
{
	if (par->sign == '\0')
		return (filler);
	if ((par->zero_f == ON && par->prec == OFF) || par->left_align == ON)
		filler[0] = par->sign;
	else
		filler[par->width - str_len - 1] = par->sign;
	return (filler);
}
