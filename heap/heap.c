#include<stddef.h>
#include "heap.h"
#include<string.h>

#include<assert.h>
static void _swap_(int32_t *data1,int32_t *data2)
{

int32_t  temp=*data1 ;
*data1=*data2;
*data2=temp;



}


static void _heapify_(int32_t data[],uint32_t len,uint32_t parent)
{


//assert(len>0 && len<MAX_HEAP_SIZE && parent>0);


	
uint32_t child=2*parent;
while(child<=len)
{
	if(child+1<=len)
	{
		if(data[child+1]>data[child])
		{
			++child;	
	
		}
	
	}


	if(data[parent]>=data[child])
	{
		break;
	}


_swap_(&data[parent],&data[child]);
parent=child;
child=2*parent;

}



}

Heap heap_new(int32_t data[],uint32_t len)
{
	//printf("\nnew0");

assert(len>0 && len<MAX_HEAP_SIZE);
uint32_t i;
Heap heap;

for(i=(len/2);i>0;--i)
{
_heapify_(data,len,i);

}
heap.size=len;

memcpy(heap.data,data,(len+1)*sizeof(int32_t));
return heap;
}




int32_t heap_size(Heap *heap)
{

assert(heap->size>0 && heap->size < MAX_HEAP_SIZE);

return heap->size;

}




int32_t heap_get_max(Heap *heap)
{
assert(heap->size > 0 && heap->size < MAX_HEAP_SIZE);

return heap->data[1];


}


int32_t heap_extract_max(Heap *heap)
{
assert(heap->size > 0 && heap->size < MAX_HEAP_SIZE);
int32_t max=heap->data[1];

heap->data[1]=heap->data[heap->size];

--heap->size;
_heapify_(heap->data,heap->size,1);

return max;
}


Heap* heap_insert(Heap *heap, int32_t key)
{

assert(heap->size > 0 && heap->size < MAX_HEAP_SIZE);

uint32_t i;

++heap->size;
i=heap->size;

while(i>1 && heap -> data[i/2]<key)
{
heap->data[i]=heap->data[i/2];
i=i/2;

}
heap->data[i]=key;
return heap;


}

void heap_data(Heap *heap)
{


heap->size=0;
memset(heap->data,0,MAX_HEAP_SIZE*sizeof(int32_t));

}



Heap *heap_sort(Heap *heap)
{

assert(heap->size>0 && heap->size<MAX_HEAP_SIZE);
uint32_t len=heap->size;

for(len=heap->size;len>=1;len--)
{
printf("\n%d",heap->data[1]);
_swap_(&heap->data[1],&heap->data[len]);
_heapify_(heap->data,len-1,1);
}

return heap;

}

