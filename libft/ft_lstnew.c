/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:52:57 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/09 10:51:45 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype t_list * ft_lstnew(void const *content, size_t content_size);
** Description Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are initialized by
** copy of the parameters of the function. If the parameter content is nul,
** the variable content is initialized to NULL and
** the variable content_size is initialized to 0 even if the parameter
** content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
** Param. #1 The content to put in the new link.
** Param. #2 The size of the content of the new link.
** Return value The new link.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (void *)malloc(content_size)))
			return (NULL);
		new->content = (void *)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
