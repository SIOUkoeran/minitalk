/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:41 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 02:13:09 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	info;

static void ft_bitmask()
{
	int	bit;
	int	i;

	bit = 8;
	i = -1;
	while (!info.message[++i])
	{
		bit = 8;
		while (--bit >= 0)
		{
			if ((info.message[i] >> bit) & 1)
				kill(info.server_pid, SIGUSR1);
			else
				kill(info.server_pid, SIGUSR2);
			sleep(0.01);
		}
	}
	if (!info.message[i])
	{
		while (bit-- > 0)
		{
			kill(info.server_pid, SIGUSR2);
			sleep(0.01);
		}
	}
}

void	ft_transfer_to_server()
{
	char	*str;

	str = info.message;
	if (!info.server_pid)
		exit(1);
	ft_bitmask();
}

int main(int args, char **argv)
{		
	if (args == 3)
	{
		info = ft_get_input(args, argv, info);
		client_act.sa_flags = SA_SIGINFO;
		sigemptyset(&client_act.sa_flags);
		sigaddset(&client_act.sa_flags, SIGINT);
		client_act.__sigaction_u.__sa_sigaction = ft_connect;
		sigaction(SIGUSR1, &client_act, NULL);
		sigaction(SIGUSR2, &client_act, NULL);
		kill(info.server_pid, SIGUSR1);
		pause();
		return (0);
	}
	else
	{
		printf("exception\n");
		exit(1);
	}
}