/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/18 19:30:42 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_len_hexa(unsigned int number)
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

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_option_u(unsigned int number)
{
	char	*str;
	int		len;

	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		str = ft_itoa_unsigned (number);
		ft_putstr_fd (str, 1);
		len = get_len_number (number);
		free (str);
		return (len);
	}
}
