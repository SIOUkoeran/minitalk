/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:43:19 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 00:42:09 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
		else
		{
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		n = 48 + n % 10;
		write(fd, &n, 1);
	}
}

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

char	*ft_to_binary(int num)
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