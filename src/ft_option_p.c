/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/07 22:55:41 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_len_uin(uintptr_t number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		number = number / 16;
		len++;
	}
	return (len);
}

void	ft_itoa_uin(uintptr_t num)
{
	if (num >= 16)
	{
		ft_itoa_uin(num / 16);
		ft_itoa_uin(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long c)
{
	int	len;

	write(1, "0x", 2);
	len = 2;
	if (c == 0)
	{
		write (1, "0", 1);
		len++;
	}
	else
	{
		ft_itoa_uin(c);
		len += get_len_uin(c);
	}
	return (len);
}
