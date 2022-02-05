 
//#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

ft_putstr(char *str){
	size_t i;
	i = 0;
	while (str[i] != '\0'){
		write(1, &str[i], 1 );
		i++;
	}

}

void ft_putchar(int var)
{
	write(1, &var, 1);
}

void ft_printstr(char * s){
	size_t i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void ft_printnumber(int number){
	char *str;

	str = ft_itoa(number);
	ft_printstr(str);
	free(str);
}

int get_len(unsigned int number){
    int len;

    len = 0;
    while(number != 0)
    {
        number = number /10;
        len++;
    }
    return (len);
}

char *ft_itoa_unsigned(unsigned int number){
    char *c;
    int len;
    int i;

    i = 0;
    len = get_len(number);
    c = malloc(sizeof(char) * (len + 1));
    c[len] = '\0';
    len--;
    while (len >= 0){
        c[len] = (number % 10) + '0';
        number = number/10;
        len--; 
    }
    return (c);
}

void ft_print_u(unsigned int number){
	char *str;
	if (number == 0)
		write(1, "0", 1);
	else
	{
		str = ft_itoa_unsigned(number);
		ft_printstr(str);
		free(str);
	}
}

void ft_print_porce(){
	write (1, "%", 1);
}

int get_len_hexa(unsigned int number){
    int len;

    len = 0;
    while(number != 0)
    {
        number = number /16;
        len++;
    }
    return (len);
}

char *ft_itoa_unsigned(unsigned int number)
{
    int i;
    int len;
    int aux;
    char *c;
    char base16[] = "0123456789ABCDEF";

    i = 0;
    len = get_len_hexa(number);
    c = malloc(sizeof(char) * (len + 1));
    c[len] = '\0';
    len--;
    while(len >= 0)
    {
        aux = (number % 16);
        c[len] = base16[aux];
        number = number / 16;
        len--;
    }
    return (c);
}

ft_print_x(unsigned int c)
{
	int i;
	char *str;

	i = 0;
	str = ft_itoa_unsigned(c);
	while(str[i])
	{
		ft_putchar(ft_tolower(str[i]));
	}
	free(str);
}

ft_print_mayus(unsigned int c)
{
	int i;
	char *str;

	i = 0;
	str = ft_itoa_unsigned(c);
	ft_printstr(str);
	free(str);
}


int ft_evaluate_param(va_list args, char *str, int i)
{
	if (str[i] == 'c') // int
		ft_printchar(va_arg(args, int));
	if (str[i] == 's') // char *
		ft_printstr(va_arg(args, char *));
		//Funcion
	if (str[i] == 'p') // unsigned long long
		//Funcion
	if (str[i] == 'd' || str[i] == 'i') // int 
		ft_print_number(va_arg(args, int));
	//if (str[i] == 'i') // int UNIR CON d por que es base 10 tambien. 
		//Funcion
	if (str[i] == 'u') // unsigned int
		ft_print_u(va_arg(args, unsigned int));
	if (str[i] == 'x') // unsigned int minuscula
		ft_print_x(va_arg(args, unsigned int));
	if (str[i] == 'X') // usigned int maysucula usar libft para mayus i minus y unir las X
		ft_print_mayus(va_arg(args, unsigned int));
	if (str[i] == '%') //  Porcentaje only 
		ft_print_porce();
	return (i);
}


int ft_printf(const char *input, ...)
{
	size_t i;
	va_list  args;

	va_start(args, input);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			// Evaluar el porcentaje
			i = ft_evaluate_param(args, input, i + 1);
		} else {
			write(1, &input[i], 1);
		}
		i++;
	}
	return (0);
}


int main(){
	char input[] = "pruebas";
	ft_printf("%s", input);
	return (0);
}
