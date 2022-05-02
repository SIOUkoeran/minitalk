/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:41 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/02 23:46:41 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	info;

int main(int args, char **argv)
{		
	if (args == 3)
	{
		info = ft_get_input(args, argv, info);
		printf("client : %d message : %s ", info.server_pid, info.message);
		ft_connect(SIGUSR1);
		ft_transfer_to_server(info);
	}
	else{
		return 0;
	}
}