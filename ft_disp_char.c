/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:44:22 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 16:54:45 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_fill_space(t_args *par, t_fill *fill)
{
	par->width--;
	if (par->width < 1)
		return ("");
	fill->width = ft_make_filler(par->width, ' ');
	if (fill->width == NULL)
		return (0);
	return (fill->width);
}

int			ft_disp_char(t_args *par)
{
	char	c;
	char	*res;
	t_fill	*fill;

	c = (char)va_arg(par->ap, unsigned int);
	fill = ft_init_fill();
	res = ft_fill_space(par, fill);
	if (res == NULL)
	{
		free_filler(fill);
		return (ERROR);
	}
	if (par->left_align == ON)
		par->printed += ft_putchar(c) + ft_putstr(res);
	else
		par->printed += ft_putstr(res) + ft_putchar(c);
	free_filler(fill);
	return (0);
}
