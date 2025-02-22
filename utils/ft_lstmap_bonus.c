/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:05:02 by akhobba           #+#    #+#             */
/*   Updated: 2024/05/24 10:53:33 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_link	*ft_lstmap(t_link *lst, void *(*f)(void *), void (*del)(void *))
{
	t_link	*new_lst;
	t_link	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(&lst->command));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			del(&new_node->command);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
