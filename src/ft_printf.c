/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:31 by amantara          #+#    #+#             */
/*   Updated: 2022/02/18 18:33:44 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_porce(void)
{
	write (1, "%", 1);
	return (1);
}

int	ft_evaluate_param(va_list args, const char *str, int i)
{
	int	leng;

	leng = 0;
	if (str[i] == 'c')
		leng = ft_option_c(va_arg(args, int));
	if (str[i] == 's')
		leng = ft_option_s(va_arg(args, char *));
	if (str[i] == 'p')
		leng = ft_print_p(va_arg(args, unsigned long long));
	if (str[i] == 'd' || str[i] == 'i')
		leng = ft_option_di(va_arg(args, int));
	if (str[i] == 'u')
		leng = ft_option_u(va_arg(args, unsigned int));
	if (str[i] == 'x')
		leng = ft_print_x(va_arg(args, unsigned int));
	if (str[i] == 'X')
		leng = ft_print_x_upper(va_arg(args, unsigned int));
	if (str[i] == '%')
		leng = ft_print_porce();
	return (leng);
}

int	ft_printf(const char *input, ...)
{
	size_t	i;
	int		leng;
	va_list	args;

	va_start(args, input);
	i = 0;
	leng = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			leng += ft_evaluate_param(args, input, i + 1);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			leng++;
		}
		i++;
	}
	va_end(args);
	return (leng);
}
