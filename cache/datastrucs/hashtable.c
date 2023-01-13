#include "hashtable.h"
#include "list.h"
#include "page.h"
#include "math.h"

#include <stdlib.h> /*malloc*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*printf*/

unsigned int GetHash(unsigned int i) {
    return (i*2654435761 % (unsigned int)pow(2, 32));
}

struct hash_t *HTableCreate(int len) {
    int i;
    struct hash_t *table = malloc(sizeof(struct hash_t));
    table->len = len;
    table->htab = malloc(len * 8);
    for (i=0; i<len; i++) {
        struct hashmap_node_t **node = table->htab + i;
        *node = NULL;
    }
    return table;
}

struct list_node_t *HTableFind(struct hash_t *table, int key) {
    int key_hash = (int)(GetHash(key) % table->len);

    struct hashmap_node_t * node = *(table->htab + key_hash);
    while (node) {
        if (node->entry.key == key) {
            return node->entry.node;
        }
        node = node->next;
    }
    return NULL;
}

void HTableInsert(struct hash_t *table, int key, struct list_node_t *lst_node) {
    int key_hash = (int)(GetHash(key) % table->len);
    struct hashmap_entry_t *entry = malloc(sizeof(struct hashmap_entry_t));
    struct hashmap_node_t *node = malloc(sizeof(struct hashmap_node_t));
    struct hashmap_node_t ** first_node = table->htab + key_hash;
    entry->key = key;
    entry->node = lst_node;
    node->entry = *entry;
    node->next = (struct hashmap_node_t *) NULL;

    if (HTableFind(table, key)) HTableRemove(table, key);

    if (*first_node) {
        struct hashmap_node_t * node_ = *first_node;
        while(node_->next) node_ = node_->next;
        node_->next = node;
    } else {
        *first_node = node;
    }
}

void HTableRemove(struct hash_t *table, int key) {
    int key_hash = (int)(GetHash(key) % table->len);
    struct hashmap_node_t ** node = table->htab + key_hash;
    if ((*node)->entry.key == key) { /*the very first node in the basket was the match*/
        struct hashmap_node_t * tmp = *node;
        *node = (*node)->next;
        free(tmp);  /*need to improve this*/
    } else {
        struct hashmap_node_t * node_ = *node;
        while (node_) {
            struct hashmap_node_t * next_node = node_->next;
            if (next_node->entry.key == key) {
                node_->next = next_node->next;
                free(next_node);  /*need to improve this*/
                break;  /*because we guarantee that each key is unique*/
            }
            node_ = next_node;
        }
    }
}

void HTableRehash(struct hash_t **table) {
    struct hash_t *new_table = HTableCreate((*table)->len * 2);
    int i;
    for (i=0; i<(*table)->len; i++) {
        struct hashmap_node_t * node = *((*table)->htab + i);
        while (node) {
            struct hashmap_node_t * next = node->next;
            HTableInsert(new_table, node->entry.key, node->entry.node);
            node = next;
        }
    }
    HTableFree(*table);
    *table = new_table;
}


void HashmapNodeFree(struct hashmap_node_t * node) {
    while (node) {
        struct hashmap_node_t * next = node->next;
        free(node);  /*probably need to improve that too*/
        node = next;
    }
}

void HTableFree(struct hash_t *table) {
    int i;
    for (i=0; i<table->len; i++) {
        struct hashmap_node_t *node = *(table->htab + i);
        HashmapNodeFree(node);
    }
    free(table->htab);
    free(table);
}
