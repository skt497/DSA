#ifndef  _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>
typedef struct _node_ Node;
typedef struct _slist_ List;

struct _slist_
{
Node *head;
Node *tail;

uint32_t length;
};

struct _node_
{
int32_t data;
Node *next;
};


List* slist_new();
uint32_t slist_length(const List *list);
List* slist_free(List*);
uint32_t slist_lookup(const List *list,int32_t key);
List* slist_add_head(List *list,int32_t data);
List* slist_add_tail(List *list,int32_t data);
List* slist_delete_head(List *list);
List* slist_delete_tail(List *list);
List* slist_add_on_data(List *list,int32_t data,uint32_t key); 
List* slist_delete_on_data(List *list,int32_t data); 
#endif

