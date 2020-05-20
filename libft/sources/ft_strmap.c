/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:58:18 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:58:18 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i] != '\0')
		new_str[i] = f(s[i]);
	return (new_str);
}
