#include <stdio.h>
#include "datastrucs/list.h"
#include "datastrucs/page.h"
/*gcc -Wall -g hello.c -o hello*/
/*-Wall : generate all possible Warnings*/
/*-g : generate debug information*/
/*-o set outfile name*/

int main()
{
    printf("we fought for nothing, now i see - it's all about life\n\n");
 
    /*create page_1 and pointer to it*/
    struct page_t page_1;
    page_1.index = 1;
    page_1.sz = 5;
    page_1.data = "some data";

    struct page_t *page_1_ptr = &page_1;
    
    /*create page_2 and pointer to it*/
    struct page_t page_2;
    page_2.index = 2;
    page_2.sz = 10;
    page_2.data = "one more data";

    struct page_t *page_2_ptr = &page_2;
    /*create pointer to page_1*/
    
    /*create list and fill with pages*/
    struct list_t *my_list = ListCreate();
    ListPushFront( my_list, page_1_ptr );
    ListPushBack( my_list, page_2_ptr );
    PrintList( my_list );
    ListFree(my_list);

    return 0;
}