#include "hashtable.h"
#include "list.h"
#include "page.h"

#include <stdlib.h> /*malloc*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*printf*/

unsigned int hash(unsigned int i) {
    return (i*2654435761 % (unsigned int)pow(2, 32));
}

struct hash_t *htable_create(int len) {
    struct hash_t *table = malloc(sizeof(struct hash_t));
    table->len = len;
    table->htab = malloc(len * 8);
    int i;
    for (i=0; i<len; i++) {
        struct hashmap_node_t **node = table->htab + i;
        *node = NULL;
    }
    return table;
}

struct list_node_t *htable_find(struct hash_t *table, int key) {
    int key_hash = (int)(hash(key) % table->len);

    struct hashmap_node_t * node = &(*(table->htab + key_hash));
    while (node) {
        if (node->entry.key == key) {
            return node->entry.node;
        }
        node = node->next;
    }
    return NULL;
}

void htable_insert(struct hash_t *table, int key, struct list_node_t *lst_node) {
    if (htable_find(table, key)) htable_remove(table, key);
    int key_hash = (int)(hash(key) % table->len);

    struct hashmap_entry_t *entry = malloc(sizeof(struct hashmap_entry_t));
    entry->key = key;
    entry->node=lst_node;
    struct hashmap_node_t *node = malloc(sizeof(struct hashmap_node_t));
    node->entry = *entry;
    node->next = NULL;

    struct hashmap_node_t *first_node = &(*(table->htab + key_hash));
    if (first_node) {
        while(first_node->next) first_node = first_node->next;
        first_node->next = node;
    } else {
        first_node = node;
    }
}

void htable_remove(struct hash_t *table, int key) {
    int key_hash = (int)(hash(key) % table->len);
    struct hashmap_node_t * node = &(*(table->htab + key_hash));
    if (node->entry.key == key) { /*the very first node in the basket was the match*/
        struct hashmap_node_t * tmp = node;
        node = tmp->next;
        free(tmp);  /*need to improve this*/
    } else {
        while (node) {
            struct hashmap_node_t * next_node = node->next;
            if (next_node->entry.key == key) {
                node->next = next_node->next;
                free(next_node);  /*need to improve this*/
                break;
            }
            node = next_node;
        }
    }
}

/*
void hashmap_node_free(struct hashmap_node_t * node) {
    while (node) {
        struct hashmap_node_t * next = node->next;
        free(&(node->entry));
        node = next;
    }
    free(node);
}
*/

void htable_free(struct hash_t *table) {
    int i;
    for (i=0; i<table->len; i++) {
        struct hashmap_node_t * node = *(table->htab + i);
        free(node);  /*probably need to improve that too*/
    }
    free(table->htab);
    free(table);
}
