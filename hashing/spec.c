#include<stdio.h>

#include "hashing.c"


void main()
{

HashTable instance=hashtable_new(5);

HashTable *h=&instance;


h=hashtable_insert_element(h,"data1");
h=hashtable_insert_element(h,"data2");
h=hashtable_insert_element(h,"data3");
h=hashtable_insert_element(h,"data4");
assert(hashtable_find(h,"data1")==1);
assert(hashtable_find(h,"data19")==0);
h=hashtable_delete_element(h,"data1");
hashtable_destroy(h);


}
