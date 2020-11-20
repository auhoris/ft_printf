/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:21:01 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 16:46:26 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;

	if (par->prec >= 0)
		par->zero_f = OFF;
	if (to_print[0] == '0')
		par->hex_f = 0;
	if (to_print[0] == '0' && par->prec == 0)
		return ("");
	if (to_print[0] == '0')
		par->hex_f = ZERO;
	str_len = (int)ft_strlen(to_print);
	if (par->prec <= str_len)
		return (to_print);
	fill->prec = ft_make_filler(par->prec, '0');
	if (fill->prec == NULL)
		return (NULL);
	ft_strncpy(&fill->prec[par->prec - str_len], to_print, str_len);
	return (fill->prec);
}

static char	*ft_treat_hex(t_args *par, char *filler, int str_len)
{
	char	*hex;

	if (par->hex_f == 0)
		return (filler);
	if (par->f_cpy[par->read] == 'x')
		hex = "0x";
	else if (par->f_cpy[par->read] == 'X')
		hex = "0X";
	if (par->left_align == ON || par->zero_f == ON)
		ft_strncpy(filler, hex, 2);
	else
		ft_strncpy(&filler[par->width - str_len - 2], hex, 2);
	return (filler);
}

static char	*ft_treat_width(t_args *par, t_fill *fill, char *to_print)
{
	int		str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(to_print);
	if (par->width <= str_len && par->hex_f == 0)
		return (to_print);
	else if (par->width < str_len + par->hex_f)
		par->width = str_len + par->hex_f;
	if (par->zero_f == ON && par->prec == OFF && par->left_align == OFF)
		gap = '0';
	if (!(fill->width = ft_make_filler(par->width, gap)))
		return (NULL);
	fill->width = ft_treat_hex(par, fill->width, str_len);
	if (par->left_align == ON)
		ft_strncpy(&fill->width[par->hex_f], to_print, str_len);
	else
		ft_strncpy(&fill->width[par->width - str_len], to_print, str_len);
	return (fill->width);
}

int			ft_disp_u(t_args *par)
{
	t_fill	*fill;
	char	*to_print;

	to_print = par->res;
	fill = ft_init_fill();
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
