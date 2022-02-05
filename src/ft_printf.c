 
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
	}153
}

int ft_evaluate_param(va_list args, char *str, int i)
{
    if (str[i] == 'c') // int
        ft_printchar(va_arg(args, int));
    if (str[i] == 's') // char *
        ft_printstr(va_arg(args, char *)
        //Funcion
    if (str[i] == 'p') // unsigned long long
        //Funcion
    if (str[i] == 'd') // int 
        //Funcion
    if (str[i] == 'i') // int UNIR CON d por que es base 10 tambien. 
        //Funcion
    if (str[i] == 'u') // unsigned int
        //Funcion
    if (str[i] == 'x') // unsigned int mayuscula
        //Funcion
    if (str[i] == 'X') // usigned int minuscula usar libft para mayus i minus y unir las X
        //Funcion
    if (str[i] == '%') //  Porcentaje only 
        //Funcion
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
