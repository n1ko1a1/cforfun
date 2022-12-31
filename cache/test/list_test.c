#include "list_test.h"

void TestPageT()
{
    struct page_t lhs = {0, 10, "tententent"};
    struct page_t rhs;

    printf("TestPageT ... \n");
    rhs.index = 0;
    rhs.sz = 10;
    rhs.data = "tententent";

    assert(lhs.index==rhs.index);
    assert(lhs.sz==rhs.sz);
    assert(lhs.data==rhs.data);
    printf("TestPageT OK \n\n");
}

void TestListNodeCreate()
{
    struct page_t page_1 = {0, 10, "tententent"};

    struct list_node_t * node_ptr_1_lhs;
    struct list_node_t * node_ptr_2_lhs;
    struct list_node_t * node_ptr_3_lhs;

    struct list_node_t node_1_rhs;
    struct list_node_t node_2_rhs;
    struct list_node_t node_3_rhs;

    node_ptr_1_lhs = ListNodeCreate(NULL, NULL, &page_1);
    node_ptr_2_lhs = ListNodeCreate(NULL, node_ptr_1_lhs, &page_1);
    node_ptr_3_lhs = ListNodeCreate(node_ptr_2_lhs, node_ptr_1_lhs, &page_1);

    node_1_rhs = (struct list_node_t) { NULL, NULL, &page_1};
    node_2_rhs = (struct list_node_t) { NULL, node_ptr_1_lhs, &page_1};
    node_3_rhs = (struct list_node_t) { node_ptr_2_lhs, node_ptr_1_lhs, &page_1};

    printf("TestListNodeCreate ...  \n");

    assert( node_ptr_1_lhs->data == node_1_rhs.data );
    assert( node_ptr_1_lhs->next == node_1_rhs.next );
    assert( node_ptr_1_lhs->prev == node_1_rhs.prev );

    assert( node_ptr_2_lhs->data == node_2_rhs.data );
    assert( node_ptr_2_lhs->next == node_2_rhs.next );
    assert( node_ptr_2_lhs->prev == node_2_rhs.prev );

    assert( node_ptr_3_lhs->data == node_3_rhs.data );
    assert( node_ptr_3_lhs->next == node_3_rhs.next );
    assert( node_ptr_3_lhs->prev == node_3_rhs.prev );
    
    free(node_ptr_1_lhs);
    free(node_ptr_2_lhs);
    free(node_ptr_3_lhs);
    printf("TestListNodeCreate OK \n\n");
}


void TestListPushFront()
{
    #define n 10  
    int i;
    struct list_t * lst;
    struct page_t pages[n];
    struct list_node_t * node;

    lst = ListCreate();  
    for (i = 0; i < n; i++) {
        pages[i] = (struct page_t) {i, 10, "hello"};
        ListPushFront(lst, &pages[i]);
    }

    node = lst->tail;
    
    printf("TestListPushFront ...  \n");

    for (i = 0; i < n; i++) {
        assert( pages[i].index == node->data->index );
        node = node->prev;
    }

    ListFree(lst);
    printf("TestListPushFront OK \n\n");
}

void TestListPushBack() {
    struct list_t * lst;
    struct list_node_t * node;
    #define n 10
    struct page_t pages[n];
    int i;

    lst = ListCreate();
    for (i = 0; i < n; i++) {
        pages[i] = (struct page_t) {i, 10, "hello"};
        ListPushBack(lst, &pages[i]);
    }

    node = lst->top;

    
    printf("TestListPushBack ...  \n");

    for (i = 0; i < n; i++) {
        assert( pages[i].index == node->data->index );
        node = node->next;
    }
    ListFree(lst);

    printf("TestListPushBack OK \n\n");
}