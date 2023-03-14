/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:18:34 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/14 17:28:35 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_sender(int proccess_id, char c)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if ((c & (1 << counter)) != 0)
			kill(proccess_id, SIGUSR1);
		else
			kill(proccess_id, SIGUSR2);
		usleep(100);
		counter++;
	}
}

int	main(int argc, char **argv)
{
	int	proccess_id;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("Geçersiz Argüman Tekrar Dene", 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	i = 0;
	proccess_id = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		bit_sender(proccess_id, argv[2][i]);
		i++;
	}
	bit_sender(proccess_id, '\n');
	return (0);
}
