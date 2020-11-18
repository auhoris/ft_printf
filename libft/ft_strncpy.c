/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:01:02 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 11:21:10 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		}
	}
	return (dst);
}
