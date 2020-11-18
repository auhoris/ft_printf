/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:21:01 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 21:26:20 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, char *str)
{
	int	str_len;
	char	*filler;

	if (str[0] == '0' && par->prec == 0)
		return ("");
	if (str[0] == '0')
		par->hex_f = ZERO;
	str_len = (int)ft_strlen(str);
	if (par->prec <= str_len)
		return (str);
	filler = ft_make_filler(par->prec, '0');
	if (filler == NULL)
		return (NULL);
	ft_strncpy(&filler[par->prec - str_len], str, str_len);
	return (filler);
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

static char	*ft_treat_width(t_args *par, char *str)
{
	char	*filler;
	int	str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(str);
	if (par->width <= str_len && par->hex_f == OFF)
		return (str);
	else if (par->width < str_len + par->hex_f)
		par->width = str_len + par->hex_f;
	if (par->zero_f == ON && par->prec == OFF && par->left_align == OFF)
		gap = '0';
	if (!(filler = ft_make_filler(par->width, gap)))
		return (NULL);
	filler = ft_treat_hex(par, filler, str_len);
	if (par->left_align == ON)
		ft_strncpy(&filler[par->hex_f], str, str_len);
	else
		ft_strncpy(&filler[par->width - str_len], str, str_len);
	return (filler);
}

int		ft_disp_u(t_args *par, char *str)
{
	if ((str = ft_treat_prec(par, str)) == NULL
			|| (str = ft_treat_width(par, str)) == NULL)
		return (ERROR);
	par->printed += ft_putstr(str);
	return (0);
}
