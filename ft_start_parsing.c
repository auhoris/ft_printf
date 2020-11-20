/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:08:54 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 12:06:16 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(t_args *par)
{
	while (ft_inset(FLAGS, par->f_cpy[par->read]))
	{
		par->f_cpy[par->read] == '-' ? par->left_align = ON : ZERO;
		par->f_cpy[par->read] == '+' ? par->plus_f = ON : ZERO;
		par->f_cpy[par->read] == ' ' ? par->space_f = ON : ZERO;
		par->f_cpy[par->read] == '0' ? par->zero_f = ON : ZERO;
		par->f_cpy[par->read] == '#' ? par->hex_f = HEX_ON : ZERO;
		par->read++;
	}
}

static void	ft_parse_width(t_args *par)
{
	char	*copy;

	if (par->f_cpy[par->read] != '*' && !IS_NUM(par->f_cpy[par->read]))
		return ;
	if (par->f_cpy[par->read] == '*')
	{
		par->width = va_arg(par->ap, int);
		par->read++;
	}
	else
	{
		copy = ft_strdup(&par->f_cpy[par->read]);
		par->width = ft_atoi(copy);
		if (copy != NULL)
			free(copy);
		while (IS_NUM(par->f_cpy[par->read]))
			par->read++;
	}
	if (par->width < 0)
	{
		par->width = -par->width;
		par->left_align = ON;
	}
}

static void	ft_parse_prec(t_args *par)
{
	char *copy;

	if (par->f_cpy[par->read] != '.')
		return ;
	par->read++;
	if (par->f_cpy[par->read] == '*')
	{
		par->prec = va_arg(par->ap, int);
		par->read++;
	}
	else
	{
		copy = ft_strdup(&par->f_cpy[par->read]);
		par->prec = ft_atoi(copy);
		if (copy != NULL)
			free(copy);
		while (IS_NUM(par->f_cpy[par->read]))
			par->read++;
	}
	if (par->prec < 0)
		par->prec = OFF;
}

static void	ft_parse_len_mod(t_args *par)
{
	if (!ft_inset(LEN_MOD, par->f_cpy[par->read]))
		return ;
	par->len_mod = 0;
	while (ft_inset(LEN_MOD, par->f_cpy[par->read]))
	{
		par->len_mod += par->f_cpy[par->read];
		par->read++;
	}
}

int			ft_start_parsing(t_args *par)
{
	if (par->format[par->read] == '\0')
		return (ERROR);
	ft_parse_flags(par);
	ft_parse_width(par);
	ft_parse_prec(par);
	ft_parse_len_mod(par);
	if (ft_inset(SPECIFIER, par->f_cpy[par->read]) == 0)
		return (ERROR);
	return (0);
}
