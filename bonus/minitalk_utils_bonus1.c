/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:10:03 by tkannane          #+#    #+#             */
/*   Updated: 2024/02/04 12:48:48 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	check_sent_msg(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("The msg was successfully sent\n");
}
