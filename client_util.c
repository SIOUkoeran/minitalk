/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:14:33 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 02:15:35 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

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

void	ft_connect(int signo, siginfo_t *siginfo_t, void *t)
{
	(void)t;
	(void)siginfo_t;

	if (!client_act.sa_flags)
		exit(1);
	if (sigaction(SIGUSR1, &client_act, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &client_act, NULL) == -1)
		exit(1);
	ft_transfer_to_server();
}