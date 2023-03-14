/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:38:18 by rcalik            #+#    #+#             */
/*   Updated: 2023/03/14 17:28:01 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	chr;
	static int	counter;

	if (signal == SIGUSR1)
		chr |= (1 << counter);
	counter++;
	if (counter == 8)
	{
		ft_putchar_fd(chr, 1);
		counter = 0;
		chr = 0;
	}
}

int	main(int argc, char **argv)
{
	int	proccess_id;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Yanlış Arguman Tekrar Deneyin.", 1);
		return (1);
	}
	proccess_id = getpid();
	ft_putstr_fd("Procces ID : ", 1);
	ft_putnbr_fd(proccess_id, 1);
	ft_putstr_fd("\nMesaj Bekleniyor...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
