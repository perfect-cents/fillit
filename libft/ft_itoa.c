/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:09:22 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/01/19 13:03:35 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = n < 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*a;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_len(n);
	if ((a = ft_strnew(len)) == NULL)
		return (NULL);
	if (n <= 0)
	{
		*a = n < 0 ? '-' : '0';
		n *= -1;
	}
	while (n)
	{
		len--;
		a[len] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
