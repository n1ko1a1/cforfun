#include "list_test.h"

void TestPageT()
{
    printf("TestPageT ... \n");
    struct page_t lhs = {0, 10, "tententent"};

    struct page_t rhs;
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
    printf("TestListNodeCreate ...  \n");
    struct page_t page_1 = {0, 10, "tententent"};

    struct list_node_t * node_ptr_1_lhs = list_node_create(NULL, NULL, &page_1);
    struct list_node_t * node_ptr_2_lhs = list_node_create(NULL, node_ptr_1_lhs, &page_1);
    struct list_node_t * node_ptr_3_lhs = list_node_create(node_ptr_2_lhs, node_ptr_1_lhs, &page_1);

    struct list_node_t node_1_rhs = { NULL, NULL, &page_1};
    struct list_node_t node_2_rhs = { NULL, node_ptr_1_lhs, &page_1};
    struct list_node_t node_3_rhs = { node_ptr_2_lhs, node_ptr_1_lhs, &page_1};
    
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
    printf("TestListPushFront ...  \n");
    struct list_t * lst = list_create();
    #define n 10
    struct page_t pages[n];
    int i;
    for (i = 0; i < n; i++) {
        pages[i] = (struct page_t) {i, 10, "hello"};
        list_push_front(lst, &pages[i]);
    }

    struct list_node_t * node = lst->tail;
    for (i = 0; i < n; i++) {
        assert( pages[i].index == node->data->index );
        node = node->prev;
    }
    list_free(lst);
    printf("TestListPushFront OK \n\n");
}

void TestListPushBack() {
    printf("TestListPushBack ...  \n");
    struct list_t * lst = list_create();
    #define n 10
    struct page_t pages[n];
    int i;
    for (i = 0; i < n; i++) {
        pages[i] = (struct page_t) {i, 10, "hello"};
        list_push_back(lst, &pages[i]);
    }

    struct list_node_t * node = lst->top;
    for (i = 0; i < n; i++) {
        assert( pages[i].index == node->data->index );
        node = node->next;
    }
    list_free(lst);
    printf("TestListPushBack OK \n\n");
}