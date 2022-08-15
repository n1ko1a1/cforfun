#include "list.h"
#include "page.h"

#include <stdlib.h> /*malloc*/
#include <stddef.h>/*NULL*/
#include <stdio.h>/*printf*/


struct list_node_t * list_node_create(struct list_node_t * next, struct list_node_t * prev, struct page_t * data)
{
    struct list_node_t *tmp = malloc( sizeof( struct list_node_t ) );
    tmp->data = data;
    tmp->next = next;
    tmp->prev = prev;
    return tmp;
}

struct list_t * list_create()
{
    struct list_t * new_list;
    new_list = malloc( sizeof( struct list_t ) );
    new_list->back = NULL;
    new_list->top = NULL;
    return new_list;
}

void list_push_front( struct list_t *lst, struct page_t *pg )
{
    struct list_node_t *tmp = malloc( sizeof( struct list_node_t ) );
    tmp->prev = NULL;
    tmp->data = pg;
    tmp->next = lst->top;
    if( lst->top )
        lst->top->prev = tmp;
    else 
        lst->back = tmp;
    lst->top = tmp; 
}

void print_list( struct list_t * lst )
{
    struct list_node_t * current = lst->top;
    while( current )
    {
        printf("index: %d\n", current->data->index );
        printf("size: %d\n", current->data->sz );
        printf("data: %s\n\n", current->data->data);
        current = current->next;
    }
}
