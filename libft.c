/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:43:19 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/02 22:25:19 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *s)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + ((int)*s - '0');
		s++;
	}
	return (result * sign);
}

int	ft_to_binary(int num)
{
	char 	*s;
	int		idx;
	
	s = malloc(sizeof(int) * 8);
	idx = 8;
	while (--idx > 0)
	{
		s[idx] = num % 2;
		num /= 2;
	}
	return (s);
}