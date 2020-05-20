/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:59:18 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:59:18 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[j]))
		j--;
	if (!(new_str = ft_strnew(j - i + 1)))
		return (NULL);
	new_str = ft_strsub(s, i, j - i + 1);
	return (new_str);
}
