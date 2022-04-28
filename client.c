/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:41 by mkim3             #+#    #+#             */
/*   Updated: 2022/04/28 19:22:26 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int args, char **argv){
	
	pid_t	client_pid;
	pid_t	server_pid;
	t_info	info;
	
	client_pid = getpid();
	if (!client_pid)
		exit(1);
	if (args == 3)
	{
		info = ft_get_input(args, argv);
		printf("client : %d message : %s ", info.server_pid, info.message);
	}
	else{
		return 0;
	}
	
}