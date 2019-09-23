#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "queue.c"

void test_queue_one()
{
	Queue q_instance=queue_new(1);
	Queue *q = &q_instance;
    QueueResult result;


    assert(queue_empty(q));
    assert(!queue_full(q));

    queue_remove(q,&result);
    assert(result.status==QUEUE_EMPTY);


    queue_add(q,100,&result);
    assert(result.status==QUEUE_OK);
    assert(queue_full(q));

    queue_add(q,101,&result);
    assert(result.status==QUEUE_FULL);

    queue_remove(q,&result);
    assert(result.data==100 && result.status==QUEUE_OK);
    assert(queue_empty(q));
}

void test_arbitrary_queue()
{
   Queue q_instance=queue_new(0);
	Queue *q = &q_instance;
    QueueResult result;

    int i;

    for(i=0; i<MAX_QUEUE_LEN; i++){
    	 queue_add(q,i,&result);
    	 assert(result.status==QUEUE_OK);
    }

    queue_add(q,i,&result);
    assert(result.status==QUEUE_FULL);

    for(i=0; i<MAX_QUEUE_LEN; i++){
    	 queue_remove(q,&result);
    	 assert(result.status==QUEUE_OK);
    }

    queue_remove(q,&result);
    assert(queue_empty(q));
    assert(result.status==QUEUE_EMPTY);


}

int main()
{
	test_queue_one();
	test_arbitrary_queue();
	printf("executed\n");
	return 0;
    exit(0);
}