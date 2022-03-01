/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:58:44 by acanterg          #+#    #+#             */
/*   Updated: 2021/07/29 01:25:01 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	signal_handler(int signum)
{
	static char	*str;
	static char	c;
	static int	i;

	if (signum == SIGUSR1)
		c = (c << 1) + 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	if (++i > 7)
	{
		if (c)
		{
			str = ft_concat_c(str, c);
		}
		else
		{
			ft_putstr(str);
			ft_putchar('\n');
			free(str);
			str = 0;
		}
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putstr("SERVER RUNNING ON PID: ");
	ft_putnbr((int)getpid());
	ft_putchar('\n');
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
