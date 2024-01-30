/*
** EPITECH PROJECT, 2023
** hdr
** File description:
** hdr
*/
#include "hdr.h"
int control(char c)
{
    if (c != 'd' && c != 'i' && c != 's' && c != 'c' && c != '%'){
        error();
        return 84;
    }
    return 0;
}

int test(const char *str, int i)
{
    while (str[i] != '\0'){
        if (str[i] == '%'){
            control(str[i + 1]);
        }
        i += 1;
    }
    return (0);
}
