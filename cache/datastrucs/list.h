#ifndef LIST_H_SENTRY
#define LIST_H_SENTRY

struct list_node_t
{
    struct list_node_t * next;
    struct list_node_t * prev;
    struct page_t * data;
};

struct list_t
{
    struct list_node_t * top;
    struct list_node_t * tail;
};

struct list_node_t * list_node_create(struct list_node_t * next, struct list_node_t * prev, struct page_t * data);

struct list_t * list_create();

/*int list_size( const struct list_t * lst );*/

/*struct page_t * list__back( struct list_t * lst);*/

/*void list_pop_back( struct list_t * lst);*/

void list_push_front( struct list_t *lst, struct page_t *pg );

void list_push_back( struct list_t *lst, struct page_t *pg );

void list_free( struct list_t * lst );

void print_list( struct list_t * lst );

/*move_upfront*/

 #endif