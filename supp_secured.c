/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hashtable generator
*/
#include "hashtable/hashtable.h"

int get_index(char *key, int (*hash)(char *, int))
{
    unsigned int i = 0;

    if (!key)
        return 84;
    i = hash(key, CAPACITY);
    return i % CAPACITY;
}

int my_strcmp(char *str, char *ref)
{
    if (!str || !ref)
        return 84;
    for (int i = 0; str[i] != '\0' || ref[i] != '\0'; i++){
        if (str[i] > ref[i])
            return 1;
        if (str[i] < ref[i])
            return -1;
    }
    return 0;
}

data_t *get_prev_nod(hashtable_t *ht, int key)
{
    if (!ht)
        return NULL;
    if (ht->data->key == key)
        return ht->data;
    while (ht->data->next != NULL && ht->data->next->key != key)
        ht->data = ht->data->next;
    return ht->data;
}

void ht_dump(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht[0].H_size; i ++){
        if (!ht[i].data)
            mini_printf("[%i]:\n", i);
        if (ht[i].data){
            mini_printf("[%i]:\n", i);
            print_data(ht[i]);
            ht[i].data = ht[i].head;
        }
    }
}

void print_data(hashtable_t ht)
{
    if (!ht.data || !ht.head)
        return;
    if (ht.data->value)
        while (ht.data){
            mini_printf("> %d - %s\n", ht.data->key, ht.data->value);
            ht.data = ht.data->next;
        }
    return;
}
