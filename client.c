/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:58:44 by acanterg          #+#    #+#             */
/*   Updated: 2021/07/29 01:21:46 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Client should receive only 2 arguments: ");
		ft_putstr("[PID] and [MESSAGE]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (*(argv[2]) != 0)
	{
		send_char(pid, *(argv[2]));
		(argv[2])++;
	}
	send_char(pid, 0);
}
