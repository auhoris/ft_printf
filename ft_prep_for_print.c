/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:54:24 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 17:42:31 by auhoris          ###   ########.fr       */
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
		par->res = ft_itoa_ll(n);
	else
		par->res = ft_itoa(n);
	if (par->res == NULL)
		return (ERROR);
	return (ft_disp_int(par));
}

int	ft_prep_u(t_args *par)
{
	size_t	n;

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
		par->res = ft_itoa_u_base("0123456789abcdef", n);
	else if (par->f_cpy[par->read] == 'X')
		par->res = ft_itoa_u_base("0123456789ABCDEF", n);
	else if (par->f_cpy[par->read] == 'u')
		par->res = ft_itoa_u_base("0123456789", n);
	if (par->res == NULL)
		return (ERROR);
	return (ft_disp_u(par));
}
