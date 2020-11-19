/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:08:47 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:51:01 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_width(t_args *par, char *str)
{
	char	*filler;
	int		str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(str);
	if (par->width <= str_len)
		return (str);
	if (par->zero_f == ON && par->left_align == OFF)
		gap = '0';
	if (!(filler = ft_make_filler(par->width, gap)))
		return (NULL);
	if (par->left_align == ON)
		ft_strncpy(filler, str, str_len);
	else
		ft_strncpy(&filler[par->width - str_len], str, str_len);
	return (filler);
}

int			ft_disp_percent(t_args *par)
{
	char	*str;

	str = "%";
	if ((str = ft_treat_width(par, str)) == NULL)
		return (ERROR);
	par->printed += ft_putstr(str);
	return (0);
}
