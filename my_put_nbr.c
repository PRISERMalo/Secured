/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
#include "hashtable/hashtable.h"

static int init_cpt(int nb)
{
    int result = 0;

    while (nb != 0) {
        nb = nb / 10;
        result = result + 1;
    }
    return result;
}

int negative(int nb)
{
    my_putchar('-');
    nb = nb * (-1);
    return nb;
}

int zero(int nb)
{
    if (nb == 0) {
        my_putchar(48);
        return 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int compteur = init_cpt(nb) - 1;
    int puissance = 1;
    int count = 0;
    int save = nb;

    if (nb < 0) {
        nb = negative(nb);
        count++;
    }
    while (save != 0 && compteur != 0) {
        puissance = puissance * 10;
        compteur = compteur - 1;
    }
    while (save != 0 && puissance >= 1) {
        my_putchar((nb / puissance) + 48);
        nb = nb % puissance;
        puissance = puissance / 10;
    }
    return count + zero(save) + init_cpt(save);
}
