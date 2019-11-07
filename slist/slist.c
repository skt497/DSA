#include <stdlib.h>
#include <stddef.h>
#include "slist.h"

 List* new_list()
 {
 	List* list;
 	/*list=(List*)malloc(sizeof(List))*/
 	list->head=NULL;
 	list->tail=NULL;
 	list->length=0;

 }
static Node* add_new_node(uint32_t data)
{
	Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;

}

List* add_on_data(List *list, uint32_t data,uint32_t key)
{
	Node *cur;
	Node *node=add_new_node(data);
	cur=list->head;
	for(;cur!=NULL && cur->data !=NULL ;cur = cur->next);
	{
	 	if(cur!=NULL)
	 		{ if(cur->data==key)
	 			{
	 
	 	
	 	          node->next=cur->next;
	 		      cur->next=node;
	 	        }
	 	      
	 	    }
	 	++list->length;

	 } return(list);
}

 uint32_t count_element(List* list)
 {
 	return(list->length);

 }

 List* delete_dup(List*list)
{
 list *p, *q, *prev, *temp;

 p= list->head;
 prev= list->head;
 q = p->next;
 while (p != NULL)
 {
 	while (q != NULL && q->data != p->data)
      { prev = q;
      	q = q->next;
      }
      if (q == NULL)
      { p = p->next;

            if (p != NULL)
               q = p->next;
       }
       else if (q->data == p->data)
       {prev->next = q->next;

            temp = q;

            q = q->next;

            free(temp);
        }     
     }
}
        

        

           

        

        


