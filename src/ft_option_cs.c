/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:26:37 by amantara          #+#    #+#             */
/*   Updated: 2022/02/18 18:34:17 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_option_c(int i)
{
	char	c;

	c = (char)i;
	ft_putchar_fd (c, 1);
	return (1);
}

int	ft_option_s(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd (str, 1);
	return (ft_strlen(str));
}
