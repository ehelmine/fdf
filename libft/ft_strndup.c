/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:21:34 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/09 10:39:32 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (n >= len)
		n = len;
	if (!(dup = (char *)malloc(sizeof(*dup) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
