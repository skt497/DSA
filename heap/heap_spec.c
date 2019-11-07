#include<stdio.h>
#include "heap.c"
void test()
{

int i;
int data[5]={0,10,20,30,40};
Heap instance=heap_new(data,4);
Heap *heap=&instance;


assert(heap_size(heap)==4);
assert(heap_get_max(heap)==40);
assert(heap_size(heap)==4);
heap_extract_max(heap);
assert(heap->size==3);
heap_insert(heap,50);

assert(heap->size==4);
assert(heap_get_max(heap)==50);
heap_sort(heap);

}
void main()
{

test();

printf("\nexecuted successfully\n");

}
