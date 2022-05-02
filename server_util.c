/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:40:01 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 02:12:53 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server_info info;

void	ft_open_server(int sig_num, siginfo_t *siginfo_t, void *t)
{
	(void)t;
	
	if (sig_num == SIGUSR1 || sig_num == SIGUSR2)
	{
		info.client_pid = siginfo_t->si_pid;
		server_act.__sigaction_u.__sa_sigaction = ft_message;
		sigaction(SIGUSR1, &server_act, NULL);
		sigaction(SIGUSR2, &server_act, NULL);
		kill(info.client_pid, sig_num);
		usleep(0.01);
	}
	else
	{
		exit(1);
	}
}

void	ft_message(int sig_num, siginfo_t *siginfo_t, void *t)
{
	(void) t;
	int bit;
	char c = '\0';

	bit = 8;
	idx = -1;
	if (sig_num == SIGUSR1)
		ch += 1 << --bit;
	else
		--bit;
	if (bit == 0)
	{
		
	}
}