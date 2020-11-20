/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:35:44 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 17:51:30 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, t_fill *fill, char *to_print)
{
	if (par->prec == OFF || par->prec >= (int)ft_strlen(to_print))
		return (to_print);
	fill->prec = malloc(sizeof(char) * (par->prec + 1));
	if (fill->prec == NULL)
		return (NULL);
	ft_strncpy(fill->prec, to_print, par->prec);
	return (fill->prec);
}

static char	*ft_treat_width(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;

	str_len = ft_strlen(to_print);
	if (par->width <= str_len)
		return (to_print);
	fill->width = ft_make_filler(par->width, ' ');
	if (fill->width == NULL)
		return (NULL);
	if (par->left_align == ON)
		ft_strncpy(fill->width, to_print, str_len);
	else
		ft_strncpy(&fill->width[par->width - str_len], to_print, str_len);
	return (fill->width);
}

int			ft_disp_str(t_args *par)
{
	char	*to_print;
	t_fill	*fill;

	fill = ft_init_fill();
	to_print = va_arg(par->ap, char *);
	if (to_print == NULL)
		to_print = "(null)";
	if ((to_print = ft_treat_prec(par, fill, to_print)) == NULL
			|| (to_print = ft_treat_width(par, fill, to_print)) == NULL)
	{
		free_filler(fill);
		return (ERROR);
	}
	par->printed += ft_putstr(to_print);
	free_filler(fill);
	return (0);
}
