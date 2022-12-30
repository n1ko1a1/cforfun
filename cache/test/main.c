#include "list_test.h"
#include "hashtable_test.h"

int main()
{
    assert(NULL==NULL);
    TestPageT();
    TestListNodeCreate();
    TestListPushFront();
    TestListPushBack();

    TestHTableCreate();
    TestHTableInsert();
    TestHTableFind();
    TestHTableRemove();
    /*
    struct page_t l;
    printf("index: %d\n", l.index );
    printf("size: %d\n", l.sz );
    printf("data: %p\n", (void*) l.data);
    printf("data: %d\n\n", (void*) l.data==NULL);

    l.data = NULL;
    printf("data: %p\n", (void*) l.data);
    printf("data: %d\n\n", (void*) l.data==NULL);
    */
    /* index sz data */ 
    assert(2==2);
    return 0;
}