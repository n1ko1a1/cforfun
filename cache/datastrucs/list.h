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

struct list_node_t * ListNodeCreate(struct list_node_t * next, struct list_node_t * prev, struct page_t * data);

struct list_t * ListCreate();

/*int list_size( const struct list_t * lst );*/

/*struct page_t * list__back( struct list_t * lst);*/

/*void list_pop_back( struct list_t * lst);*/

/*given an existing node we move it to the top*/
void ListMoveUpfront( struct list_t *lst, struct list_node_t *p);

void ListPushFront( struct list_t *lst, struct page_t *pg );

void ListPushBack( struct list_t *lst, struct page_t *pg );

void ListFree( struct list_t * lst );

void PrintList( struct list_t * lst );

/*move_upfront*/

 #endif