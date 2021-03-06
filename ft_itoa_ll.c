/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:45:50 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/18 12:49:02 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_reverse(char *s)
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

static int		ft_nbr_len(long long n)
{
	int	i;

	i = 1;
	while ((n /= 10) != 0)
		i++;
	return (i);
}

static int		ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char			*ft_itoa_ll(long long n)
{
	int			nbr_len;
	char		*p_res;
	int			i;
	long long	sign;
	int			plus;

	plus = 1;
	nbr_len = ft_nbr_len(n);
	if ((sign = n) < 0)
		plus++;
	p_res = malloc(sizeof(*p_res) * (nbr_len + plus));
	if (p_res == 0)
		return (0);
	i = -1;
	while (++i < nbr_len)
	{
		p_res[i] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (sign < 0)
		p_res[i++] = '-';
	p_res[i] = '\0';
	ft_reverse(p_res);
	return (p_res);
}
