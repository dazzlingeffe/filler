/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:54:49 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:54:49 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*str;
	size_t		length;
	intmax_t	nbr;

	nbr = n;
	length = ft_nblen(nbr);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[--length] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
