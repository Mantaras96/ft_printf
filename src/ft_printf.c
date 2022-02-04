 
//#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

// Struct con todo lo que necesitamos para nuestro printf
typedef struct s_print                       
{                        
      va_list  args;    // arg to print out                    
      int   wdt;        // width                
      int   prc;        // precision              
      int   zero;       // zero padding               
      int   pnt;        // .     
      int   dash;       // -               
      int   tl;         // total_length (return value)              
      int   sign;       // pos or neg number               
      int   is_zero;    // is number zero                 
      int   perc;       // %               
      int   sp;         // space flag ' '            
}    t_print;


//Inicializamos la struct con 0
t_print *start_print(t_print *print)
{
    print->wdt = 0;
    print->prc = 0;
    print->zero = 0;
    print->pnt = 0;
    print->dash = 0;    
    print->tl = 0;
    print->sign = 0;
    print->is_zero = 0;
    print->perc = 0;
    print->sp = 0;
    return (print);
}

ft_putstr(char *str){
    size_t i;

    i = 0;
    while (str[i] != '\0'){
        write(1, &str[i], 1 );
        i++;
    }

}

void ft_print_char(t_print *tab)
{

}

int ft_evaluate_param(va_list args, char *str, int i)
{
    if (str[i] == 'c') // int
        ft_printchar(va_arg(args, int));
    if (str[i] == 's') // char *
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
    t_print *str;
    size_t i;
    va_list  args;

    str = malloc(sizeof(t_print));
    if (!str)
        return (0);
    start_print(str);
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
    printf("%s", str->args);


    return (0);
}


int main(){
    char input[] = "pruebas";
    ft_printf("%s", input);
    return (0);
}
