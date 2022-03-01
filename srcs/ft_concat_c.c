/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 01:24:25 by acanterg          #+#    #+#             */
/*   Updated: 2021/07/29 01:24:38 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	exit_error(char *str)
{
	free(str);
	str = 0;
	quit_error();
}

char	*ft_concat_c(char *str, char c)
{
	char	*new_str;
	int		i;

	if (!str)
	{
		new_str = malloc(sizeof(char) * 2);
		if (!new_str)
			quit_error();
		new_str[0] = c;
		new_str[1] = 0;
	}
	else
	{
		new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
		if (!new_str)
			exit_error(str);
		i = -1;
		while (str[++i])
			new_str[i] = str[i];
		free(str);
		str = 0;
		new_str[i++] = c;
		new_str[i] = 0;
	}
	return (new_str);
}
