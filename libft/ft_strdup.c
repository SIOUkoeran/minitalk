/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:24:46 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 21:53:23 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	length;

	length = (size_t) ft_strlen(s1);
	temp = malloc(sizeof(char) * (length + 1));
	if (temp == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(temp, s1, length + 1);
	return (temp);
}
