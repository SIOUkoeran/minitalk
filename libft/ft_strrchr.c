/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:41:02 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:04:42 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;

	length = ft_strlen(s);
	if (length == 0)
		return (NULL);
	while (length != -1)
	{
		if (s[length] == c)
		{
			return ((char *)s + length);
		}
		length--;
	}
	return (NULL);
}
