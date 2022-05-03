/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:05 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/03 22:41:41 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_message1(int sig_num, siginfo_t *siginfo_t, void *t)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	
	(void)t;
	c |= (sig_num == SIGUSR1);
	if (++bit == 8)
	{
		bit = 0;
		if (c >= 0 && c <= 127)
			ft_putchar_fd(c, 1);
		else
			ft_putchar_fd('\n', 1);
		c = 0;
	}
	else
		c <<= 1;
}

int main(int args, char **argv)
{
	struct sigaction server_act;
	(void)argv;
	
	if (args != 1)
		exit(1);
	server_act.sa_flags = SA_SIGINFO;
	sigemptyset(&server_act.sa_flags);
	server_act.sa_sigaction = ft_message1;
	sigaction(SIGUSR1, &server_act, NULL);
	sigaction(SIGUSR2, &server_act, NULL);
	ft_putnbr_fd(getpid(),1);
	ft_putchar_fd('\n', 1);
	while(1)
		pause();
	return (0);
}