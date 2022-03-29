/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:01:35 by hlucas            #+#    #+#             */
/*   Updated: 2022/03/29 13:01:36 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	str_len = ft_strlen(str + start);
	if (str_len < len)
		len = str_len;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
