/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_back_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:05:30 by akhobba           #+#    #+#             */
/*   Updated: 2024/06/11 09:59:29 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_dbl_lstadd_back(t_link **lst, t_link *new)
{
	t_link	*last;

	if (NULL == lst)
		return ;
	if (NULL == *lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}
