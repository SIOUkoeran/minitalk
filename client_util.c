/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:14:33 by mkim3             #+#    #+#             */
/*   Updated: 2022/04/28 19:28:26 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

t_info	ft_get_input(int args, char** argv)
{
	t_info info;
	
	if (args < 3)
		exit(1);
	info.server_pid = ft_atoi(argv[1]);
	info.message = argv[2];
	return (info);
}