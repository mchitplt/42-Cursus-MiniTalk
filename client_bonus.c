/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mupolat <mupolat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:42:39 by mupolat           #+#    #+#             */
/*   Updated: 2023/04/07 18:46:21 by mupolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	show_error(int err)
{
	if (err == 0)
	{
		ft_putstr_fd("you must entervalid PID\n", 1);
		exit(1);
	}
	else if (err == 1)
	{
		ft_putstr_fd("you must enter valid string\n", 1);
		exit(1);
	}
	else if (err == 2)
	{
		ft_putstr_fd("something happened, couldn't send the data\n", 1);
		exit(1);
	}
	else if (err == 3)
	{
		ft_putstr_fd("wrong PID format\n", 1);
		exit(1);
	}
	else if (err == 4)
	{
		ft_putstr_fd("you can send one string\n", 1);
		exit(1);
	}
}

void	ft_send_data(int data, int pid)
{
	unsigned char	c;
	int				i;

	c = data;
	i = 128;
	while (i > 0)
	{
		if (c / i)
		{
			if (kill(pid, SIGUSR1) == -1)
				show_error(2);
			c -= i;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				show_error(2);
		}
		i /= 2;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (!av[1])
		show_error(0);
	else if (!av[2])
		show_error(1);
	if (ac == 3)
	{
		if (av[1])
			while (av[1][i])
				if (!ft_strchr("0123456789", av[1][i++]))
					show_error(3);
		str = av[2];
		pid = ft_atoi(av[1]);
		while (*(str))
			ft_send_data(*(str)++, pid);
		ft_send_data('\n', pid);
	}
	else if (ac > 3)
		show_error(4);
	return (0);
}
