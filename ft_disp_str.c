/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:35:44 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:50:06 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, char *str)
{
	if (par->prec == OFF || par->prec >= (int)ft_strlen(str))
		return (str);
	str = ft_strndup(str, par->prec);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_treat_width(t_args *par, char *str)
{
	int		str_len;
	char	*filler;

	str_len = ft_strlen(str);
	if (par->width <= str_len)
		return (str);
	filler = ft_make_filler(par->width - str_len, ' ');
	if (filler == NULL)
		return (NULL);
	if (par->left_align == ON)
		str = ft_strjoin(str, filler);
	else
		str = ft_strjoin(filler, str);
	return (str);
}

int			ft_disp_str(t_args *par)
{
	char	*str;

	str = va_arg(par->ap, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	if ((str = ft_treat_prec(par, str)) == NULL
			|| (str = ft_treat_width(par, str)) == NULL)
		return (ERROR);
	par->printed += ft_putstr(str);
	return (0);
}
