/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:55:27 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:55:27 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	**tmp;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	tmp = &newlst;
	while (lst)
	{
		*tmp = f(lst);
		tmp = &(*tmp)->next;
		lst = lst->next;
	}
	return (newlst);
}
