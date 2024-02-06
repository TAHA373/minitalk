/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:10:35 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/30 11:34:10 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	display_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			display_error("Bad pid\n");
		i++;
	}
	i = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX || res <= 0)
		display_error("Bad pid\n");
	return (res);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
