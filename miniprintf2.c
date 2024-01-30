/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** print f
*/
#include "hdr.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i += 1;
    }
    return (i - 1);
}

int do_it(const char *b, va_list list, int i)
{
    if ((b[i + 1] == 'd' || b[i + 1] == 'i'))
        return (my_put_nbr(va_arg(list, int)) + 1);
    if (b[i + 1] == 'c'){
        my_putchar(va_arg(list, int));
        return 1;
    }
    if (b[i + 1] == 's')
        return (my_putstr(va_arg(list, char *)) + 1);
    if (b[i + 1] == '%'){
        my_putchar('%');
        return 1;
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    int length = 0;
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0'){
        if (format[i] == '%' && format[i + 1] != '\0'){
            length += do_it(format, list, i);
            i += 1;
        } else {
            my_putchar(format[i]);
            length += 1;
        }
        i += 1;
    }
    va_end(list);
    return length;
}
