/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:16:18 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/18 12:44:26 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, char *str)
{
	int	str_len;
	char	*filler;

	if (str[0] == '0' && par->prec == 0)
		return ("");
	str_len = (int)ft_strlen(str);
	if (par->prec <= str_len)
		return (str);
	filler = ft_make_filler(par->prec, '0');
	if (filler == NULL)
		return (NULL);
	ft_strncpy(&filler[par->prec - str_len], str, str_len);
	return (filler);
}

static char	*ft_treat_width(t_args *par, char *str)
{
	int	str_len;
	char	gap;
	char	*filler;

	gap = ' ';
	str_len = (int)ft_strlen(str);
	if (par->sign == '\0' && par->width <= str_len)
		return (str);
	if (par->zero_f == ON && par->prec == OFF && par->left_align == OFF)
		gap = '0';
	if (par->width < str_len)
		par->width = str_len;
	if (par->sign && par->width == str_len)
		par->width++;
	if (!(filler = ft_make_filler(par->width, gap)))
		return (NULL);
	if (par->left_align == ON && par->sign)
		ft_strncpy(filler + 1, str, str_len);
	else if (par->left_align == ON)
		ft_strncpy(filler, str, str_len);
	else
		ft_strncpy(&filler[par->width - str_len], str, str_len);
	filler = ft_set_sign(par, filler, str_len);
	return (filler);
}

int	ft_disp_int(t_args *par, char *str)
{
	str = ft_check_sign(par, str);
	if ((str = ft_treat_prec(par, str)) == NULL
			|| (str = ft_treat_width(par, str)) == NULL)
		return (ERROR);
	par->printed += ft_putstr(str);
	return (0);
}
