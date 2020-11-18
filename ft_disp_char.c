/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:44:22 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:53:11 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_fill_space(t_args *par)
{
	char	*fill;

	par->width--;
	if (par->width < 1)
		return ("");
	fill = ft_make_filler(par->width, ' ');
	if (!fill)
		return (0);
	return (fill);
}

int		ft_disp_char(t_args *par)
{
	char	c;
	char	*fill;

	c = (char)va_arg(par->ap, unsigned int);
	fill = ft_fill_space(par);
	if (!fill)
		return (ERROR);
	if (par->left_align == ON)
		par->printed += ft_putchar(c) + ft_putstr(fill);
	else
		par->printed += ft_putstr(fill) + ft_putchar(c);
	return (0);
}
