/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:58:35 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:58:35 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	while (src[++i] != '\0' && i < len)
		dst[i] = src[i];
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}
