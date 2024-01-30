/*
** EPITECH PROJECT, 2023
** B-CPE-101-RUN-1-1-miniprintf-malo.priser
** File description:
** hdr
*/

#ifndef HDR_H_
    #define HDR_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>

int error(void);
int test(const char *, int);
int my_put_nbr(int);
void my_putchar(char);
int mini_printf(const char *format, ...);

#endif /* !HDR_H_ */
