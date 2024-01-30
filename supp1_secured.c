/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hashtable generator
*/

#include "hashtable/hashtable.h"

int ht_delete(hashtable_t *ht, char *key)
{
    int index = get_index(key, ht->hash);
    int hasch = ht->hash(key, CAPACITY);
    data_t *next = NULL;

    if (!ht || (my_strcmp(NFOUND, ht_search(ht, key)) == 0))
        return 84;
    if (ht[index].data->key == hasch){
        ht[index].head = ht[index].data->next;
        free(ht[index].data);
        ht[index].data = ht[index].head;
        return 0;
    }
    while (ht[index].data->next->key != hasch)
        ht[index].data = ht[index].data->next;
    if (ht[index].data->next->next)
        next = ht[index].data->next->next;
    free(ht[index].data->next);
    ht[index].data->next = next;
    ht[index].data = ht[index].head;
    return 0;
}

void delete_hashtable(hashtable_t *ht)
{
    data_t tmp = {.key = 0, .next = NULL, .value = NULL};

    if (!ht)
        return;
    for (int i = 0; i < ht[i].H_size; i ++){
        while (ht[i].data){
            tmp.next = ht[i].data->next;
            free(ht[i].data);
            ht[i].data = tmp.next;
        }
    }
    free(ht);
}
