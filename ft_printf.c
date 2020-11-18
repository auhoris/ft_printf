/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:51:51 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/18 12:58:13 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_display(t_args *par)
{
	if (par->f_cpy[par->read] == 'c')
		return (ft_disp_char(par));
	else if (par->f_cpy[par->read] == 's')
		return (ft_disp_str(par));
	else if (par->f_cpy[par->read] == 'd' || par->f_cpy[par->read] == 'i')
		return (ft_prep_int(par));
	else if (par->f_cpy[par->read] == 'u' ||
			par->f_cpy[par->read] == 'x' || par->f_cpy[par->read] == 'X')
		return (ft_prep_u(par));
	else if (par->f_cpy[par->read] == 'p')
		return (ft_disp_p(par));
	else if (par->f_cpy[par->read] == '%')
		return (ft_disp_percent(par));
	else
		return (ERROR);
	return (0);
}

static void	ft_init_args(t_args *par)
{
	par->left_align = OFF;
	par->width = OFF;
	par->prec = OFF;
	par->zero_f = OFF;
	par->plus_f = OFF;
	par->minus_f = OFF;
	par->space_f = OFF;
	par->hex_f = ZERO;
	par->sign = '\0';
	par->len_mod = OFF;
	par->filler = ' ';
}

static int	ft_start_process(t_args *par)
{
	par->printed = 0;
	par->f_cpy = (char *)par->format;
	par->read = 0;
	while (par->f_cpy[par->read] != '\0')
	{
		if (par->f_cpy[par->read] == '%')
		{
			par->read++;
			ft_init_args(par);
			if (ft_start_parsing(par) == ERROR)
				return (ERROR);
			if (switch_display(par) == ERROR)
				return (ERROR);
		}
		else
			par->printed += write(1, &par->f_cpy[par->read], 1);
		par->read++;
	}
	return (par->printed);
}

int		ft_printf(char *format, ...)
{
	t_args	*par;

	if (!(par = malloc(sizeof(t_args))))
		return (ERROR);
	par->format = format;
	if (format)
	{
		va_start(par->ap, format);
		if ((par->printed = ft_start_process(par)) == ERROR)
			return (ERROR);
		va_end(par->ap);
	}
	return (par->printed);
}
