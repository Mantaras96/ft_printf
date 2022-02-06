# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}


int	get_len_number(unsigned int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
        len++;
		number = number / 10;
		
	}
    printf("\nLogitud  %d\n", len);
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
	while (number > 0)
	{
		c[len] = (number % 10) + '0';
		number = number / 10;
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
		free (str);
		return (0);
	}
}


int	ft_option_c(int i)
{
	char	c;
	c = (char)i;
	write(1, &c, 1);
	return (1);
}

int	ft_evaluate_param(va_list args, const char *str, int i)
{
	int	leng;
	leng = 0;
	if (str[i] == 'c')
		leng = ft_option_c(va_arg(args, int));
	// if (str[i] == 's')
	// 	leng = ft_option_s(va_arg(args, char *));
	// if (str[i] == 'p')
	// 	leng = ft_print_p(va_arg(args, unsigned long long));
	// if (str[i] == 'd' || str[i] == 'i')
	// 	leng = ft_option_di(va_arg(args, int));
	if (str[i] == 'u')
		leng = ft_option_u(va_arg(args, unsigned int));
	// if (str[i] == 'x')
	// 	leng = ft_print_x(va_arg(args, unsigned int));
	// if (str[i] == 'X')
	// 	leng = ft_print_x_upper(va_arg(args, unsigned int));
	// if (str[i] == '%')
	// 	leng = ft_print_porce();
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

int main()
{
    int i = -1;

    ft_printf("%u", 10);

    return (0);
}