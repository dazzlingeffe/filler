/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:59:39 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:59:39 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa_base(uintmax_t number, int base, int uppercase)
{
	char		*str;
	size_t		length;

	if (base < 2 || base > 36)
		return (NULL);
	length = ft_uilen(number, base);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (number == 0)
		str[0] = '0';
	else if (uppercase == 1)
		while (number > 0)
		{
			str[--length] = BASE_UPPER[number % base];
			number /= base;
		}
	else
		while (number > 0)
		{
			str[--length] = BASE_LOWER[number % base];
			number /= base;
		}
	return (str);
}
