#include "hashtable_test.h"

void TestHTableCreate() {
    int n;
    struct hash_t * table;
    int i;

    n = 10;
    table = HTableCreate(n);
    assert(table->len == n);

    printf("TestHTableCreate ... \n");
    for (i=0; i<n; i++) {
        assert(*(table->htab + i) == NULL);
    }
    HTableFree(table);
    printf("TestHTableCreate OK \n\n");
}

void TestHTableInsert() {
    int n;
    int m;
    int i;
    struct page_t page;
    struct hash_t * table;
    struct list_node_t * nodes[5];

    m = 5;
    n = 10;
    table = HTableCreate(n);
    page = (struct page_t) {0, 10, "sdlkfjsdlkfjs"};
    for (i=0; i<m; i++) nodes[i] = ListNodeCreate(NULL, NULL, &page);

    for (i=0; i<m; i++) {
        if (i > 2) HTableInsert(table, 2, nodes[i]);
        else HTableInsert(table, i, nodes[i]);
    }

    printf("TestHTableInsert ... \n");

    assert(HTableFind(table, 0) == nodes[0]);
    assert(HTableFind(table, 1) == nodes[1]);
    assert(HTableFind(table, 2) == nodes[m-1]);

    HTableFree(table);
    printf("TestHTableInsert OK \n\n");
}

void TestHTableFind() {
    int n;
    int m;
    int i;
    struct page_t page;
    struct hash_t * table;
    struct list_node_t * nodes[5];
    
    m = 5;
    n = 10;
    table = HTableCreate(n);
    page = (struct page_t) {0, 10, "sdlkfjsdlkfjs"};
    for (i=0; i<m; i++) nodes[i] = ListNodeCreate(NULL, NULL, &page);

    for (i=0; i<m; i++) {
        if (i > 3) HTableInsert(table, 3, nodes[i]);
        else HTableInsert(table, i, nodes[i]);
    }

    printf("TestHTableFind ... \n");

    assert(HTableFind(table, 0) == nodes[0]);
    assert(HTableFind(table, 1) == nodes[1]);
    assert(HTableFind(table, 2) == nodes[2]);
    assert(HTableFind(table, 3) == nodes[m-1]);
    assert(HTableFind(table, 4) == NULL);
    assert(HTableFind(table, 5) == NULL);
    assert(HTableFind(table, 100) == NULL);

    HTableFree(table);
    printf("TestHTableFind OK \n\n");
}

void TestHTableRemove() {
    struct page_t page;
    int n = 5;
    int i;
    struct hash_t * table = HTableCreate(n);
    struct list_node_t * nodes[12];
    int keys[] = {0, 1, 2, 3, 4, 5, 6, 120, 1031, 420, -100, 36};
    int m = 12;

    page = (struct page_t) {0, 10, "sdlkfjsdlkfjs"};

    for (i=0; i<m; i++) {
        nodes[i] = ListNodeCreate(NULL, NULL, &page);
        HTableInsert(table, keys[i], nodes[i]);
    }

    printf("TestHTableRemove ... \n");
    for (i=0; i<m; i++) assert(HTableFind(table, keys[i]) == nodes[i]);
    for (i=0; i<m; i++) HTableRemove(table, keys[m-i-1]);
    for (i=0; i<m; i++) assert(HTableFind(table, keys[i]) == NULL);
    printf("TestHTableRemove OK \n\n");
}

void TestHTableRehash() {
    struct page_t page;
    int n = 6;
    int i;
    struct hash_t * table = HTableCreate(n);

    struct list_node_t * nodes[12];
    int m = 12;
    int keys[] = {0, 1, 2, 3, 4, 5, 6, 120, 1031, 420, -100, 36};
    page = (struct page_t) {0, 10, "sdlkfjsdlkfjs"};

    for (i=0; i<m; i++) {
        nodes[i] = ListNodeCreate(NULL, NULL, &page);
        HTableInsert(table, keys[i], nodes[i]);
    }


    HTableRehash(&table);

    
    printf("TestHTableRehash ... \n");
    assert(table->len == n*2);
    for (i=0; i<m; i++) assert(HTableFind(table, keys[i]) == nodes[i]);
    for (i=0; i<m; i++) HTableRemove(table, keys[i]);
    for (i=0; i<m; i++) assert(HTableFind(table, keys[i]) == NULL);
    printf("TestHTableRehash OK \n\n");
}