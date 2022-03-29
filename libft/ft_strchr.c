/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:57:26 by hlucas            #+#    #+#             */
/*   Updated: 2022/03/29 12:57:28 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*fin;

	i = 0;
	fin = (char *)s;
	if (c == 0)
	{
		while (fin[i] != '\0')
			i++;
		return (&fin[i]);
	}
	while ((fin[i] != '\0') && (fin[i] != c))
		i++;
	if (fin[i] == '\0')
		return (NULL);
	return (&fin[i]);
}
