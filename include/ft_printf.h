/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:36:11 by amantara          #+#    #+#             */
/*   Updated: 2022/02/18 19:35:43 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_option_c(int i);
int		ft_option_s(char *str);

int		ft_option_di(int number);

int		ft_print_p(unsigned long long c);
void	ft_itoa_uin(uintptr_t num);
int		get_len_uin(uintptr_t number);

int		ft_option_u(unsigned int number);
void	ft_put_hex(unsigned int num, const char format);
int		get_len_hexa(unsigned int number);	

int		ft_print_x(unsigned int c);
int		ft_print_x_upper(unsigned int c);
char	*ft_itoa_unsigned(unsigned int number);
int		get_len_number(unsigned int number);
int		ft_print_porce(void);
int		ft_evaluate_param(va_list args, const char *str, int i);

int		ft_printf(const char *input, ...);

#endif