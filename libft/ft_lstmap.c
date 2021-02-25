/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:04:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/01/09 13:10:14 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&begin, (*del));
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}
