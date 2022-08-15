#include <stdio.h>
#include "list.h"
#include "page.h"
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
    
    /*vreate list and fill with pages*/
    struct list_t *my_list = list_create();
    list_push_front( my_list, page_1_ptr );
    list_push_front( my_list, page_2_ptr );
    print_list( my_list );

    return 0;
}