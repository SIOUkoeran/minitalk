/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:05 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 00:42:26 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int args, char **argv)
{
	void(argv);
	if (args != 1)
		exit(1);
	server_act.sa_flags = SA_SIGINFO;
	server_act.__sigaction_u.__sa_sigaction = ft_open_server;
	sigemptyset(&client_act.sa_flags);
	sigaddset(&client_act.sa_flags, SIGINT);
	sigaction(SIGUSR1, &client_act, NULL);
	sigaction(SIGUSR2, &client_act, NULL);
	ft_put_nbr(getpid(),1);
	while(1)
		pause();
}