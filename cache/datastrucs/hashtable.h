#ifndef HASHMAP_H_SENTRY
#define HASHMAP_H_SENTRY

struct hashmap_entry_t {
    int key;
    struct list_node_t *node;
};

struct hashmap_node_t {
    struct hashmap_node_t *next;
    struct hashmap_entry_t entry;
};

struct hash_t {
    struct hashmap_node_t **htab;
    int len;
};

/*create and empty hash table*/
struct hash_t *htable_create(int len);

/*search for a list_node_t by the key*/
struct list_node_t *htable_find(struct hash_t *table, int key);

/*insert pair (key, value)*/
void htable_insert(struct hash_t *table, int key, struct list_node_t *lst_node);

/*removes pair (key, value)*/
void htable_remove(struct hash_t *table, int key);

/*free memory*/
void htable_free(struct hash_t *h);

#endif