/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:03:39 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/16 22:37:38 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
