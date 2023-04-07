/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mupolat <mupolat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:48:39 by mupolat           #+#    #+#             */
/*   Updated: 2023/04/07 18:51:42 by mupolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include   <unistd.h>
# include   <stdlib.h>
# include   <signal.h>

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);
void	show_error(int err);
void	ft_send_data(int data, int pid);
void	convert_char(int data);
void	sig_handler(int sig);

#endif