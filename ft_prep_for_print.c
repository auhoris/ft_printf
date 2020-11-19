/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:54:24 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/19 12:51:17 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prep_int(t_args *par)
{
	char			*str;
	long long int	n;

	str = NULL;
	if (par->len_mod == OFF)
		n = va_arg(par->ap, int);
	else if (par->len_mod == 'l')
		n = va_arg(par->ap, long int);
	else if (par->len_mod == 'h' + 'h')
		n = (char)va_arg(par->ap, int);
	else if (par->len_mod == 'h')
		n = (short int)va_arg(par->ap, int);
	else if (par->len_mod == 'l' + 'l')
		n = va_arg(par->ap, long long int);
	else
		return (ERROR);
	if (par->len_mod == 'l' || par->len_mod == 'l' + 'l')
		str = ft_itoa_ll(n);
	else
		str = ft_itoa(n);
	if (str == NULL)
		return (ERROR);
	return (ft_disp_int(par, str));
}

int	ft_prep_u(t_args *par)
{
	char	*str;
	size_t	n;

	str = NULL;
	if (par->len_mod == OFF)
		n = va_arg(par->ap, unsigned int);
	else if (par->len_mod == 'l')
		n = va_arg(par->ap, unsigned long int);
	else if (par->len_mod == 'h' + 'h')
		n = (unsigned char)va_arg(par->ap, unsigned int);
	else if (par->len_mod == 'h')
		n = (unsigned short int)va_arg(par->ap, unsigned int);
	else if (par->len_mod == 'l' + 'l')
		n = va_arg(par->ap, unsigned long long int);
	else
		return (ERROR);
	if (par->f_cpy[par->read] == 'x')
		str = ft_itoa_u_base("0123456789abcdef", n);
	else if (par->f_cpy[par->read] == 'X')
		str = ft_itoa_u_base("0123456789ABCDEF", n);
	else if (par->f_cpy[par->read] == 'u')
		str = ft_itoa_u_base("0123456789", n);
	if (str == NULL)
		return (ERROR);
	return (ft_disp_u(par, str));
}
