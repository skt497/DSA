#include <assert.h>
#include "bst.h"
#include "bst.c"

void bst_test()
{

	BST b =  bst_new();
	BST *bst = &b;

	bst =  bst_add(bst,10);
	bst =  bst_add(bst,7);
	bst =  bst_add(bst,14);
	bst =  bst_add(bst,9);
	bst =  bst_add(bst,18);
	bst =  bst_add(bst,3);
	assert (bst->mass == 6);
    assert(bst_find(bst,7)==1);
    assert(bst_height(bst)==3);

    //bst = bst_delete(bst,18);
    //bst = bst_delete(bst,3);

    //assert (bst->mass == 4);
    //assert(bst_find(bst,18)!=1);
    //assert(bst_height(bst)==3);
   bst = bst_traversal_inorder_recursive(bst);
   //bst = bst_traversal_inorder_iterative(bst);
   bst = bst_traversal_preorder_recursive(bst);
   bst = bst_traversal_postorder_recursive(bst);
}

int main()
{
	bst_test();
	printf("EXECUTED \n ");
	return 0;
}


