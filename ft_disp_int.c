/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:16:18 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 16:38:15 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;

	if (to_print[0] == '0' && par->prec == 0)
		return ("");
	str_len = (int)ft_strlen(to_print);
	if (par->prec <= str_len)
		return (to_print);
	fill->prec = ft_make_filler(par->prec, '0');
	if (fill->prec == NULL)
		return (NULL);
	ft_strncpy(&fill->prec[par->prec - str_len], to_print, str_len);
	return (fill->prec);
}

static char	*ft_treat_width(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(to_print);
	if (par->sign == '\0' && par->width <= str_len)
		return (to_print);
	if (par->zero_f == ON && par->prec == OFF && par->left_align == OFF)
		gap = '0';
	if (par->width < str_len)
		par->width = str_len;
	if (par->sign && par->width == str_len)
		par->width++;
	if (!(fill->width = ft_make_filler(par->width, gap)))
		return (NULL);
	if (par->left_align == ON && par->sign)
		ft_strncpy(fill->width + 1, to_print, str_len);
	else if (par->left_align == ON)
		ft_strncpy(fill->width, to_print, str_len);
	else
		ft_strncpy(&fill->width[par->width - str_len], to_print, str_len);
	return (ft_set_sign(par, fill->width, str_len));
}

int			ft_disp_int(t_args *par)
{
	t_fill	*fill;
	char	*to_print;

	fill = ft_init_fill();
	to_print = ft_check_sign(par, par->res);
	if ((to_print = ft_treat_prec(par, fill, to_print)) == NULL
			|| (to_print = ft_treat_width(par, fill, to_print)) == NULL)
	{
		free_filler(fill);
		free(par->res);
		return (ERROR);
	}
	par->printed += ft_putstr(to_print);
	free(par->res);
	free_filler(fill);
	return (0);
}
