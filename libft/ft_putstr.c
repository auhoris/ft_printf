/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:52:06 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/16 17:53:22 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}
