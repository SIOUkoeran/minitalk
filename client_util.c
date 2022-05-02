/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:14:33 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/02 23:46:09 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	ft_connect(int signal_num, t_info info)
{
	info.act.sa_flags = SA_SIGINFO;
	sigemptyset(&info.act.sa_mask);
	if (signal_num == SIGUSR1)
	{
		sigaction(SIGUSR1, &info.act, NULL);
		sigaction(SIGUSR2, &info.act, NULL);
	}
	else
		exit(1);
}

t_info	ft_get_input(int args, char** argv, t_info info)
{	
	if (args < 3)
		exit(1);
	info.server_pid = ft_atoi(argv[1]);
	if (!info.server_pid)
		exit(1);
	info.client_pid = getpid();
	if (!info.client_pid)
		exit(1);
	info.message = argv[2];
	if (!info.message)
		exit(1);
	return (info);
}

static void	ft_free_str_and_bit(char *str, char *bit)
{
	free(str);
	free(bit);
}

static void ft_bitmask(char str, t_info info)
{
	char	*str;
	char	*bit;
	char	temp;

	str = ft_to_binary((int) str);
	if (!str)
		exit(1);
	bit = "10000000";
	while (!str++ && !bit++)
	{
		temp = str & bit;
		if (temp == 1)
			kill(info.server_pid, SIGUSR1);
		else
			kill(info.server_pid, SIGUSR2);
	}
	ft_free_str_and_bit(str, bit);
}

void	ft_transfer_to_server(t_info info)
{
	pid_t	server;
	char	*str;
	
	server = info.server_pid;
	str = info.message;
	if (!server)
		exit(1);
	while (!str)
	{
		ft_bitmask(str, info);
		str++;
	}
}