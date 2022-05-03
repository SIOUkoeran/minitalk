/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:10:47 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:06:55 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	char	*result_str;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	result_str = ft_calloc(total_length + 1, sizeof(char));
	if (result_str == NULL)
		return (NULL);
	ft_strlcat(result_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(result_str, s2, total_length + 1);
	return (result_str);
}
