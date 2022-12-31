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

/*create and empty GetHash table*/
struct hash_t *HTableCreate(int len);

/*search for a list_node_t by the key*/
struct list_node_t *HTableFind(struct hash_t *table, int key);

/*insert pair (key, value)*/
void HTableInsert(struct hash_t *table, int key, struct list_node_t *lst_node);

/*removes pair (key, value)*/
void HTableRemove(struct hash_t *table, int key);

/*free memory*/
void HTableFree(struct hash_t *h);

/*rehash the table*/
void HTableRehash(struct hash_t **table);

#endif