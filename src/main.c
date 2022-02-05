#include <stdio.h>
#include <stdlib.h>

// int get_len(unsigned int number){
//     int len;

//     len = 0;
//     while(number != 0)
//     {
//         number = number /10;
//         len++;
//     }
//     return (len);
// }

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

char *ft_itoa_unsigned(unsigned int number){
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

// char *ft_itoa_unsigned(unsigned int number){
//     char *c;
//     int len;
//     int i;

//     i = 0;
//     len = get_len(number);
//     c = malloc(sizeof(char) * (len + 1));
//     c[len] = '\0';
//     len--;
//     if (number == 0){
//         return ("0");
//     }
//     while (len >= 0){
//         c[len] = (number % 10) + '0';
//         number = number/10;
//         len--; 
//     }
//     return (c);
// }



int main(){
    unsigned int numero = 1232133345;

    printf("%s", ft_itoa_unsigned(numero));
    return (0);
}