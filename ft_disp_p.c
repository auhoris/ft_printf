/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:34:20 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:52:02 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_treat_prec(t_args *par, char *str)
{
	size_t	str_len;
	char	*filler;

	if (str[0] == '0' && par->prec == 0)
		return ("0x");
	if (str == NULL  && par->prec != 0)
		str = "0";
	str_len = ft_strlen(str) + ft_strlen("0x");
	filler = malloc(sizeof(*filler) * (str_len + 1));
	if (filler == NULL)
		return (NULL);
	ft_strncpy(filler, "0x", 2);
	ft_strncpy(&filler[2], str, str_len);
	return (filler);
}

static char	*ft_treat_width(t_args *par, char *str)
{
	char	*filler;
	int	str_len;
	char	gap;

	gap = ' ';
	str_len = (int)ft_strlen(str);
	if (str == NULL && par->prec == 0)
		return ("0x");
	if (par->width <= str_len)
		return (str);
	if (par->zero_f == ON)
		return (str);
	if (!(filler = ft_make_filler(par->width, gap)))
		return (NULL);
	if (par->left_align == ON)
		ft_strncpy(filler, str, str_len);
	else
		ft_strncpy(&filler[par->width - str_len], str, str_len);
	return (filler);
}

int	ft_disp_p(t_args *par)
{
	char	*str;

	str = ft_itoa_u_base("0123456789abcdef", va_arg(par->ap, long long));
	if ((str = ft_treat_prec(par, str)) == NULL
			|| (str = ft_treat_width(par, str)) == NULL)
		return (ERROR);
	par->printed += ft_putstr(str);
	return (0);
}
