/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:40:24 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/17 19:36:51 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

size_t		ft_nbr_base_len(size_t n, size_t base_len)
{
	size_t	len;

	len = 1;
	while ((n /= base_len) != 0)
		len++;
	return (len);
}

char		*ft_itoa_u_base(char *base, size_t n)
{
	char	*res;
	size_t	base_len;
	size_t	nbr_len;
	size_t	i;

	base_len = ft_strlen(base);
	nbr_len = ft_nbr_base_len(n, base_len);
	if (!(res = malloc(sizeof(*res) * (nbr_len + 1))))
		return (NULL);
	i = 0;
	while (i < nbr_len)
	{
		res[i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	res[i] = '\0';
	ft_reverse(res);
	return (res);
}
