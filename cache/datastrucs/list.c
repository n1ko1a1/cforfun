#include "list.h"
#include "page.h"

#include <stdlib.h> /*malloc*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*printf*/


struct list_node_t * ListNodeCreate(struct list_node_t * next, struct list_node_t * prev, struct page_t * data)
{
    struct list_node_t *tmp = malloc( sizeof( struct list_node_t ) );
    tmp->data = data;
    tmp->next = next;
    tmp->prev = prev;
    return tmp;
}

struct list_t * ListCreate()
{
    struct list_t * new_list = malloc( sizeof( struct list_t ) );
    new_list->tail = NULL;
    new_list->top = NULL;
    return new_list;
}

void ListPushFront( struct list_t *lst, struct page_t *pg )
{
    struct list_node_t *tmp = malloc( sizeof( struct list_node_t ) );
    tmp->prev = NULL;
    tmp->data = pg;
    tmp->next = lst->top;
    if( lst->top )
    {
        lst->top->prev = tmp;
        tmp->next = lst->top;
        tmp->prev = NULL;
    }
    else 
        lst->tail = tmp;
    lst->top = tmp; 
}

void ListPushBack( struct list_t *lst, struct page_t *pg )
{
    struct list_node_t *tmp = malloc( sizeof( struct list_node_t ) );
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->data = pg;
    if( lst->tail )
    {
        tmp->prev = lst->tail;
        lst->tail->next = tmp;
    }
    else 
        lst->top = tmp;
    lst->tail = tmp; 
}

void ListMoveUpfront( struct list_t *lst, struct list_node_t *p) {
    if (lst->top == p) return;
    if (lst->tail == p) {
        lst->tail = p->prev;
    }
    lst->top->prev = p;
    p->prev->next = p->next;
    p->next = lst->top;
    lst->top = p;
    p->prev = NULL;
}

void PrintList( struct list_t * lst )
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

void ListFree( struct list_t * lst )
{
    struct list_node_t * current = lst->top;
    while(current)
    {   
        struct list_node_t * tmp = current->next;
        free(current);
        current = tmp;
    }
    free(lst);
    /*you cannot use this pointer anymore 
    reuse this list*/
}
