/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:59:03 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:59:03 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wordlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && !(ft_isseparator(s[i], c)))
		i++;
	return (i);
}

static char			*ft_storeword(char const *s, char c)
{
	unsigned int	i;
	char			*tmp;

	i = -1;
	if (!(tmp = ft_strnew(ft_wordlen(s, c))))
		return (NULL);
	while (s[++i] != '\0' && !(ft_isseparator(s[i], c)))
		tmp[i] = s[i];
	return (tmp);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	words;
	unsigned int	nofword;
	char			**tab;

	if (!s)
		return (NULL);
	nofword = 0;
	words = ft_cntwords(s, c);
	if (!(tab = ft_strnew2d(words)))
		return (NULL);
	while (*s != '\0')
	{
		if (!(ft_isseparator(*s, c)))
		{
			if (!(tab[nofword] = ft_storeword(s, c)))
				return (NULL);
			nofword++;
			while (*s != '\0' && !ft_isseparator(*s, c))
				s++;
		}
		else
			s++;
	}
	tab[nofword] = 0;
	return (tab);
}
