/*
** EPITECH PROJECT, 2023
** error
** File description:
** error
*/
#include "hdr.h"

int error(void)
{
    return (write(2, "Wrong arguments", 16));
}
