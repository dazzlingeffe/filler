/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:56:02 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:56:02 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len)
		{
			len--;
			*(unsigned char *)(dst + len) = *(unsigned char*)(src + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
