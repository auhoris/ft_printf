/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:03:39 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 15:00:30 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fill	*ft_init_fill(void)
{
	t_fill	*fill;

	fill = malloc(sizeof(t_fill));
	fill->width = NULL;
	fill->prec = NULL;
	return (fill);
}

char	*ft_make_filler(int size, char fill)
{
	char *filler;

	filler = malloc(sizeof(*filler) * (size + 1));
	if (!filler)
		return (0);
	ft_memset(filler, fill, size);
	filler[size] = '\0';
	return (filler);
}

void	free_filler(t_fill *fill)
{
	if (fill->width != NULL)
		free(fill->width);
	if (fill->prec != NULL)
		free(fill->prec);
	free(fill);
}
