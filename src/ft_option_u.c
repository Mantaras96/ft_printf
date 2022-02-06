/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/06 18:50:32 by amantara         ###   ########.fr       */
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

char	*ft_itoa_unsigned_hexa(unsigned int number)
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
