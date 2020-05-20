/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:59:35 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:59:35 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_uilen(uintmax_t number, int base)
{
	size_t	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		++length;
	}
	return (length);
}
