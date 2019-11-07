#ifndef _INCLUDED_SLIST_H
#define _INCLUDED_SLIST_H
#include <stdio.h>
#include <stdint.h>

 typedef struct _slist_ List;
 typedef struct _node_ Node;
 
 struct _slist_
 {
 	 Node* head;
 	 Node* tail;
 	 uint32_t length;
 };

 

 struct _node_
 {
 	uint32_t data;
 	Node* next;

 };


  List* new_list();
  List* add_on_data(List*, uint32_t data, uint32_t key);
  uint32_t count_element(List*);
  List* delete_dup(List*);

#endif