/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:35:52 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 16:59:05 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*ans;

	if (!lst || !f)
		return (0);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (0);
	lst = lst->next;
	ans = new;
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (0);
		new = new->next;
		lst = lst->next;
	}
	return (ans);
}
