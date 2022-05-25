/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/05/26 00:38:03 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_len_number(unsigned int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int number)
{
	char	*c;
	int		len;

	len = get_len_number(number);
	c = malloc(sizeof(char) * (len + 1));
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (c);
}

int	ft_print_x_upper(unsigned int c)
{
	if (c == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_put_hex(c, 'X');
	return (get_len_hexa(c));
}

int	ft_print_x(unsigned int c)
{
	if (c == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_put_hex(c, 'x');
	return (get_len_hexa(c));
}
