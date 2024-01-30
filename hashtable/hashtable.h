/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "../hdr.h"
    #define HASHTABLE_H
    #define CAPACITY 12 // Size of the HashTable.
    #define NFOUND "value not found"
    #define ABS(x) ((x < 0) ? (-x) : (x))
typedef struct data_s {
    int key;
    char *value;
    struct data_s *next;
}data_t;

typedef struct hashtable_s {
    struct data_s *head;
    int (*hash)(char *, int);
    int H_size;
    data_t *data;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
void print_data(hashtable_t ht);
data_t *get_prev_nod(hashtable_t *ht, int key);
int my_strcmp(char *str, char *ref);
int get_index(char *key, int (*hash)(char *, int));

#endif /* HASHTABLE_H */
