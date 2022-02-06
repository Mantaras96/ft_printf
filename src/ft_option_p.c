/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/06 17:48:58 by amantara         ###   ########.fr       */
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

char	*ft_itoa_uin(uintptr_t number)
{
	int		i;
	int		len;
	int		aux;
	char	*c;
	char	base16[] = "0123456789ABCDEF";

	i = 0;
	len = get_len_hexa(number);
	c = malloc(sizeof(char) * (len + 1));
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		aux = (number % 16);
		c[len] = base16[aux];
		number = number / 16;
		len--;
	}
	return (c);
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
		ft_putstr_fd(ft_itoa_uin(c), 1);
		len += get_len_uin(c);
	}
	return (len);
}
