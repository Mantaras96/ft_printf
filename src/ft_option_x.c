/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/06 18:58:24 by amantara         ###   ########.fr       */
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
	int		i;

	i = 0;
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
	int		i;
	char	*str;

	if(c == 0)
	{
		write(1, "0", 1);
		return(1);	
	}
	i = 0;
	str = ft_itoa_unsigned_hexa(c);
	ft_putstr_fd(str, 1);
	free (str);
	return (get_len_hexa(c));
}

int	ft_print_x(unsigned int c)
{
	int		i;
	char	*str;
	int		len;

	if(c == 0)
	{
		write(1, "0", 1);
		return(1);	
	}
	i = 0;
	str = ft_itoa_unsigned_hexa(c);
	len = ft_strlen(str);
	while (str[i])
	{
		ft_putchar_fd(ft_tolower(str[i]), 1);
		i++;
		
	}
		
	free(str);
	return (len);
}
