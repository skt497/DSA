#include <assert.h>
#include "slist.h"
#include "slist.c"

void arbitrary_test()
{
	List *list=new_list();
	assert(count_element(list)==0);
	printf("enter the element to insert");
	int n;
	scanf("%d",&n);

	add_on_data(list, n,20);
	assert(count_element(list));
	
}

int main()
{
	
	void arbitrary_test();

	return 0;
}
