/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:34:20 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 16:41:28 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, t_fill *fill, char *to_print)
{
	size_t	str_len;

	if (to_print[0] == '0' && par->prec == 0)
		return ("0x");
	if (to_print == NULL && par->prec != 0)
		to_print = "0";
	str_len = ft_strlen(to_print) + ft_strlen("0x");
	fill->prec = malloc(sizeof(char) * (str_len + 1));
	if (fill->prec == NULL)
		return (NULL);
	ft_strncpy(fill->prec, "0x", 2);
	ft_strncpy(&fill->prec[2], to_print, str_len);
	return (fill->prec);
}

static char	*ft_treat_width(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(to_print);
	if (to_print == NULL && par->prec == 0)
		return ("0x");
	if (par->width <= str_len)
		return (to_print);
	if (par->zero_f == ON)
		return (to_print);
	if (!(fill->width = ft_make_filler(par->width, gap)))
		return (NULL);
	if (par->left_align == ON)
		ft_strncpy(fill->width, to_print, str_len);
	else
		ft_strncpy(&fill->width[par->width - str_len], to_print, str_len);
	return (fill->width);
}

int			ft_disp_p(t_args *par)
{
	t_fill	*fill;
	char	*to_print;

	par->res = ft_itoa_u_base("0123456789abcdef", va_arg(par->ap, long long));
	fill = ft_init_fill();
	to_print = par->res;
	if ((to_print = ft_treat_prec(par, fill, to_print)) == NULL
			|| (to_print = ft_treat_width(par, fill, to_print)) == NULL)
	{
		free_filler(fill);
		free(par->res);
		return (ERROR);
	}
	par->printed += ft_putstr(to_print);
	free_filler(fill);
	free(par->res);
	return (0);
}
