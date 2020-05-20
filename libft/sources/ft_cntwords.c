/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:53:52 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:53:52 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_cntwords(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (!ft_isseparator(s[i], c))
		{
			words++;
			while (!ft_isseparator(s[i], c) && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (words);
}
