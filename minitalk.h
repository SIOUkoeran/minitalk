/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:44:32 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 00:44:14 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H_
# define MINITALK_H_

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

struct	sigaction server_act;
struct  sigaction client_act;

typedef struct s_info{
	pid_t 	server_pid;
	pid_t 	client_pid;
	char* 	message;
} t_info;

typedef struct s_server_info{
	pid_t	client_pid;
} t_server_info;

int		ft_atoi(char *s);
t_info	ft_get_input(int a, char** c, t_info info);
void	ft_transfer_to_server();
char	*ft_to_binary(int num);
void	ft_connect(int sig_num, siginfo_t *siginfo_t, void *t);
void	ft_open_server(int sig_num, siginfo_t *siginfo_t, void *t);
void	ft_putnbr_fd(int n, int fd);
#endif