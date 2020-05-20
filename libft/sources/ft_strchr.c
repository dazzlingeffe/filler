/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:57:18 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:57:18 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	sym = (char)c;
	while (*ptr && *ptr != sym)
		ptr++;
	return ((*ptr == sym) ? ptr : NULL);
}
