/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:05 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/02 22:00:21 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signo)
{
	
}

int main(int args, char **argv){
	pid_t			pid;
	t_server_info	*info;
	int				result;
	
	pid = getpid();
	printf("server pid : %d\n", pid);
	result = sigemptyset(&(info->act.sa_mask));
	if (result == -1)
		exit(1);
	sigaddset(&(info->act.sa_mask, SIGQUIT));
	signal(SIGINT, (void *)sig_handler);
	while (1)
	{
		
	}
}