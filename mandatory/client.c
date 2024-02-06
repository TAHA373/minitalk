/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:16:23 by tkannane          #+#    #+#             */
/*   Updated: 2024/02/04 18:09:34 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_bit(int pid, int nb)
{
	if (nb == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			display_error("Error to send SIGUSER1\n");
	}
	if (nb == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			display_error("Error to send SIGUSER2\n");
	}
}

void	ft_extract_bit(int pid, char to_send)
{
	int		nb;
	char	c;

	c = 0;
	while (c < 8)
	{
		nb = (to_send >> c++) & 1;
		usleep(500);
		ft_send_bit(pid, nb);
	}
}

void	ft_send_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_extract_bit(pid, str[i]);
		i++;
	}
}

void	ft_check_args(int ac, char **av, int *pid)
{
	if (ac != 3)
		display_error("Bad arguments\n");
	*pid = ft_atoi(av[1]);
	if (av[2][0] == '\0')
		display_error("Empty message\n");
}

int	main(int ac, char **av)
{
	int		pid;

	pid = 0;
	ft_check_args(ac, av, &pid);
	ft_send_char(pid, av[2]);
	return (0);
}
