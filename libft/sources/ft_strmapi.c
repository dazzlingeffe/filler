/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:58:22 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:58:22 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_new;

	if (!s || !f)
		return (NULL);
	if (!(str_new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str_new[i] = f(i, s[i]);
	return (str_new);
}
