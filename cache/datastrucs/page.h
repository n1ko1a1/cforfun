#ifndef PAGE_H_SENTRY
#define PAGE_H_SENTRY

struct page_t
{
    int index; /* page index 1, 2, ..., n */
    int sz; /* page size */
    char * data; /* page data */
};

void slow_get_page( int n, struct page_t * pg);

#endif