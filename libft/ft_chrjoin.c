/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:30:02 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 19:36:58 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrjoin(char *str, char ch)
{
	size_t	str_len;
	char	*ptr;
	int		i;

	if (!str)
		return (NULL);
	str_len = ft_strlen((char *)str);
	ptr = malloc(str_len + sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i++] = ch;
	ptr[i] = '\0';
	free(str);
	return (ptr);
}