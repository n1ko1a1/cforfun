#include <assert.h>
#include "list.h"
#include "page.h"
#include <stddef.h>

void test_page_t()
{
    printf("test_page_t_begin \n");
    struct page_t lhs = {0, 10, "tententent"};

    struct page_t rhs;
    rhs.index = 0;
    rhs.sz = 10;
    rhs.data = "tententent";

    assert(lhs.index==rhs.index);
    assert(lhs.sz==rhs.sz);
    assert(lhs.data==rhs.data);
    printf("test_page_t_end \n\n");
}

void test_list_node_create()
{
    printf("test_list_node_create \n");
    struct page_t page_1 = {0, 10, "tententent"};

    struct list_node_t * node_ptr_1_lhs = list_node_create(NULL, NULL, &page_1);
    struct list_node_t * node_ptr_2_lhs = list_node_create(NULL, node_ptr_1_lhs, &page_1);
    struct list_node_t * node_ptr_3_lhs = list_node_create(node_ptr_2_lhs, node_ptr_1_lhs, &page_1);

    struct list_node_t node_1_rhs = { NULL, NULL, &page_1};
    struct list_node_t node_2_rhs = { NULL, &node_1_rhs, &page_1};
    struct list_node_t node_3_rhs = { &node_2_rhs, &node_1_rhs, &page_1};
    
    assert( node_ptr_1_lhs->data = node_1_rhs.data );
    assert( node_ptr_1_lhs->next = node_1_rhs.next );
    assert( node_ptr_1_lhs->prev = node_1_rhs.prev );

    assert( node_ptr_2_lhs->data = node_2_rhs.data );
    assert( node_ptr_2_lhs->next = node_2_rhs.next );
    assert( node_ptr_2_lhs->prev = node_2_rhs.prev );

    assert( node_ptr_3_lhs->data = node_3_rhs.data );
    assert( node_ptr_3_lhs->next = node_3_rhs.next );
    assert( node_ptr_3_lhs->prev = node_3_rhs.prev );
    printf("test_list_node_create \n\n");
}

int main()
{
    test_page_t();
    test_list_node_create();

    struct page_t l;
    printf("index: %d\n", l.index );
    printf("size: %d\n", l.sz );
    printf("data: %p\n", (void*) l.data);
    printf("data: %d\n\n", (void*) l.data==NULL);

    l.data = NULL;
    printf("data: %p\n", (void*) l.data);
    printf("data: %d\n\n", (void*) l.data==NULL);
    /* index sz data */ 
    assert(2==2);
    assert(2==-2);
    return 0;
}