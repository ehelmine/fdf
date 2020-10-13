/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:22:08 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/08 16:54:53 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype char * ft_itoa(int n);
** Description Allocate (with malloc(3)) and returns a “fresh” string
** ending with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
** Param. #1 The integer to be transformed into a string.
** Return value The string representing the integer passed as argument.
*/

#include "libft.h"
#include <stdlib.h>

static char	*ft_nmber_thre(int ilnth, int n, char *nw)
{
	int res;
	int i;

	i = 0;
	if (nw[0] == '-')
		i = 1;
	res = 0;
	while (ilnth >= i)
	{
		res = n % 10 + 48;
		nw[ilnth] = res;
		ilnth--;
		n = n / 10;
	}
	return (nw);
}

static char	*ft_negativ_val(int ilnth, int n)
{
	char *nw;

	ilnth = ilnth + 1;
	if (!(nw = (char *)malloc(sizeof(*nw) * (ilnth + 1))))
		return (NULL);
	if (n == -2147483648)
		nw[10] = 56;
	nw[0] = '-';
	return (nw);
}

char		*ft_itoa(int n)
{
	char	*nw;
	int		ilnth;

	ilnth = ft_check_int(n);
	if (n >= 0)
	{
		if (!(nw = (char *)malloc(sizeof(*nw) * (ilnth + 1))))
			return (NULL);
	}
	else
	{
		if (!(nw = ft_negativ_val(ilnth, n)))
			return (NULL);
		if (n == -2147483648)
			n = 214748364;
		else
			n = n * -1;
		ilnth++;
	}
	nw[ilnth] = '\0';
	ilnth--;
	if (nw[0] == '-' && n == 214748364)
		ilnth--;
	nw = ft_nmber_thre(ilnth, n, nw);
	return (nw);
}
