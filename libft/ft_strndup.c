/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:40:19 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:38:32 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	char	*dup;
	int	min_len;
	int	i;

	min_len = ((int)ft_strlen(src) < n) ? ft_strlen(src) : n;
	dup = malloc(sizeof(*dup) * (min_len + 1));
	i = -1;
	while (++i < min_len)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
