/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:58:42 by tkannane          #+#    #+#             */
/*   Updated: 2024/02/05 11:28:47 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>

void	ft_putstr(char *str);
void	display_error(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	check_sent_msg(int sig);

#endif