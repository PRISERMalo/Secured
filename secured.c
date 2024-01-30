/*
** EPITECH PROJECT, 2024
** secured
** File description:
** create hash table
*/
#include "hashtable/hashtable.h"

int hash(char *key, int len)
{
    int i = 0;

    if (!len)
        return 84;
    (void)len;
    for (int j = 0; key[j]; j++)
        i += ((int)key[j] / 3 * (j + 1));
    return ABS(i);
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_hashtable = malloc(sizeof(hashtable_t) * (len + 1));

    if (!len || !new_hashtable)
        return NULL;
    for (int i = 0; i < len; i++){
        new_hashtable[i].hash = hash;
        new_hashtable[i].H_size = len;
        new_hashtable[i].data = NULL;
    }
    new_hashtable[len].hash = hash;
    new_hashtable[len].H_size = len;
    new_hashtable[len].data = NULL;
    new_hashtable[len].head = NULL;
    return new_hashtable;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int i = get_index(key, ht->hash);
    int hasch = ht->hash(key, CAPACITY);
    char *value = NULL;

    if (!ht)
        return NULL;
    if (!ht[i].data)
        return NFOUND;
    while (ht[i].data){
        if (ht[i].data && ht[i].data->key == hasch)
            value = ht[i].data->value;
        ht[i].data = ht[i].data->next;
    }
    ht[i].data = ht[i].head;
    if (!value)
        return NFOUND;
    return value;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int i = get_index(key, ht->hash);
    int hasch = ht->hash(key, CAPACITY);
    data_t *new_node = malloc(sizeof(data_t));

    if (!ht || !new_node)
        return 84;
    if (my_strcmp(NFOUND, ht_search(ht, key)) != 0){
        while (ht[i].data->key != hasch)
            ht[i].data = ht[i].data->next;
        ht[i].data = ht[i].head;
        ht[i].data->value = value;
        free(new_node);
        return 0;
    }
    new_node->key = ht->hash(key, CAPACITY);
    new_node->value = value;
    new_node->next = ht[i].data;
    ht[i].data = new_node;
    ht[i].head = new_node;
    return 0;
}
