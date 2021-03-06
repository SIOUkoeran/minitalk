/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:44:32 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 22:41:16 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H_
# define MINITALK_H_

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_info{
	pid_t 	server_pid;
	pid_t 	client_pid;
	char	*message;
} t_info;

#endif