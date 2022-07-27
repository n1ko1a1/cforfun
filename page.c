#include "page.h"

struct page
{
    int index; /* page index 1, 2, ..., n */
    int sz; /* page size */
    char * data; /* page data */
};