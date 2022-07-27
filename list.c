#include "list.h"

struct list_node_t
{
    struct list_node_t * next;
    struct list_node_t * prev;
    struct page_t * data;
};

struct list_t
{
    struct list_node_t * top;
    struct list_node_t * back;
};