/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:53:16 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/08 14:51:17 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
** Description Takes as a parameter a link’s pointer address and frees the
** memory of the link’s content using the function del given as
** a parameter, then frees the link’s memory using free(3). The
** memory of next must not be freed under any circumstance.
** Finally, the pointer to the link that was just freed must be set to NULL
** (quite similar to the function ft_memdel in the mandatory part).
** Param. #1 The adress of a pointer to a link that needs to be freed.
** Return value None.
** Libc functions free(3)
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
