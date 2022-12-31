#include "hashtable_test.h"

void TestHTableCreate() {
    printf("TestHTableCreate ... \n");
    int n = 10;
    struct hash_t * table = htable_create(n);
    assert(table->len == n);
    int i;
    for (i=0; i<n; i++) {
        assert(*(table->htab + i) == NULL);
    }
    htable_free(table);
    printf("TestHTableCreate OK \n\n");
}

void TestHTableInsert() {
    printf("TestHTableInsert ... \n");
    struct page_t page = {0, 10, "sdlkfjsdlkfjs"};
    int n = 10;
    struct hash_t * table = htable_create(n);
    struct list_node_t * node1 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node2 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node3 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node4 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node5 = list_node_create(NULL, NULL, &page);

    htable_insert(table, 0, node1);
    htable_insert(table, 1, node2);
    htable_insert(table, 2, node3);
    htable_insert(table, 2, node4);
    htable_insert(table, 2, node5);

    assert(htable_find(table, 0) == node1);
    assert(htable_find(table, 1) == node2);
    assert(htable_find(table, 2) == node5);


    htable_free(table);
    printf("TestHTableInsert OK \n\n");
}

void TestHTableFind() {
    printf("TestHTableFind ... \n");
    struct page_t page = {0, 10, "sdlkfjsdlkfjs"};
    int n = 10;
    struct hash_t * table = htable_create(n);
    struct list_node_t * node1 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node2 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node3 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node4 = list_node_create(NULL, NULL, &page);
    struct list_node_t * node5 = list_node_create(NULL, NULL, &page);

    htable_insert(table, 0, node1);
    htable_insert(table, 1, node2);
    htable_insert(table, 2, node3);
    htable_insert(table, 3, node4);
    htable_insert(table, 3, node5);

    assert(htable_find(table, 0) == node1);
    assert(htable_find(table, 1) == node2);
    assert(htable_find(table, 2) == node3);
    assert(htable_find(table, 3) == node5);
    assert(htable_find(table, 4) == NULL);
    assert(htable_find(table, 5) == NULL);
    assert(htable_find(table, 100) == NULL);


    htable_free(table);
    printf("TestHTableFind OK \n\n");
}

void TestHTableRemove() {
    printf("TestHTableRemove ... \n");
    struct page_t page = {0, 10, "sdlkfjsdlkfjs"};
    int n = 5;
    int i;
    struct hash_t * table = htable_create(n);

    struct list_node_t * nodes[10];
    int keys[] = {0, 1, 2, 3, 4, 5, 6, 120, 1031, 420, -100, 36};
    int m = 12;
    for (i=0; i<m; i++) {
        nodes[i] = list_node_create(NULL, NULL, &page);
        htable_insert(table, keys[i], nodes[i]);
    }

    for (i=0; i<m; i++) assert(htable_find(table, keys[i]) == nodes[i]);
    for (i=0; i<m; i++) htable_remove(table, keys[m-i-1]);
    for (i=0; i<m; i++) assert(htable_find(table, keys[i]) == NULL);
    printf("TestHTableRemove OK \n\n");
}

void TestHTableRehash() {
    printf("TestHTableRehash ... \n");
    struct page_t page = {0, 10, "sdlkfjsdlkfjs"};
    int n = 6;
    int i;
    struct hash_t * table = htable_create(n);

    struct list_node_t * nodes[12];
    int m = 12;
    int keys[] = {0, 1, 2, 3, 4, 5, 6, 120, 1031, 420, -100, 36};


    for (i=0; i<m; i++) {
        nodes[i] = list_node_create(NULL, NULL, &page);
        htable_insert(table, keys[i], nodes[i]);
    }


    htable_rehash(&table);

    assert(table->len == n*2);
    for (i=0; i<m; i++) assert(htable_find(table, keys[i]) == nodes[i]);
    for (i=0; i<m; i++) htable_remove(table, keys[i]);
    for (i=0; i<m; i++) assert(htable_find(table, keys[i]) == NULL);
    printf("TestHTableRehash OK \n\n");
}