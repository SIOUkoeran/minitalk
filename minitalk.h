/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:44:32 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/02 23:44:25 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H_
# define MINITALK_H_

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

typedef struct s_info{
	pid_t 	server_pid;
	pid_t 	client_pid;
	struct	sigaction act;	
	char* 	message;
} t_info;

typedef struct s_server_info{
	pid_t 		server_pid;
	sigset_t 	set;
	struct 		sigaction act;
} t_server_info;

int		ft_atoi(char *s);
void	ft_get_input(int a, char** c);
void	ft_transfer_to_server(t_info info);
int		ft_to_binary(int num);
void	ft_connect(int num);
#endif