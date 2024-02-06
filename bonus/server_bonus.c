/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:16:30 by tkannane          #+#    #+#             */
/*   Updated: 2024/02/04 18:12:32 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_end_msg(int pid)
{
	if (kill(pid, SIGUSR2) == -1)
		display_error("Can't find end msg\n");
}

void	use_signal(int nb, siginfo_t *sig_info, void *unused)
{
	static unsigned char	c;
	static int				b;
	static int				client_current_pid;

	if (client_current_pid == 0)
		client_current_pid = sig_info->si_pid;
	else if (client_current_pid != sig_info->si_pid)
	{
		c = 0;
		b = 0;
		client_current_pid = sig_info->si_pid;
	}
	c |= (nb << b++);
	if (b == 8)
	{
		if (c == '\0')
			ft_end_msg(client_current_pid);
		ft_putchar(c);
		b = 0;
		c = 0;
	}
	(void)unused;
}

void	check_signal2(int nb, siginfo_t *sig_info, void *unused)
{
	if (nb == SIGUSR1)
		use_signal(0, sig_info, unused);
	else if (nb == SIGUSR2)
		use_signal(1, sig_info, unused);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = check_signal2;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		display_error("Error in SIGUSR1\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		display_error("Error in SIGUSR2\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
