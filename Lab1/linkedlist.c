#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

list_t *create_list ()
{
    list_t *list = malloc (sizeof(list_t));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void free_list (list_t *list)
{
free(list);
}

int list_size (list_t *list)
{

    return list->size;
}

void list_append (list_t *list, int item)
{
node_t *newN = malloc(sizeof(node_t));
newN->data = item;
newN->next = NULL;

if(list->last ==NULL){
	list->first= newN;
	list->last = newN;

}else{
	list->last->next = newN;
	list->last = newN;
}
list->size++;
}

bool list_insert (list_t *list, int item, int index)
{
    if(list->first==NULL){
	    return false;
    }
    node_t *node = list->first;
    for(int i=0; i< index; i++){
	    node=node->next;
	    if(node==NULL){
		    return false;
	    }
    }
    int temp = node->data;
    node->data = item;
    node_t *currentN = list->first;
    node_t *newN = malloc(sizeof(node_t));
    newN->data = temp;
    while(list->last->data!=currentN->data){
	    if(currentN->next->data>=newN->data){
		    newN->next = currentN->next;
		    currentN->next=newN;
		    list->size++;
		    return true;
	    }
	    else{
		    currentN = currentN->next;
	    }
    }
    if(list->last->data == currentN->data){
	    currentN->next = newN;
    }
    list->size++;
    return true;
}

bool list_remove (list_t *list, int index)
{
    node_t *removedN = list->first;
    if(removedN==NULL){
	    return false;
    }
    node_t *preNode = NULL;
    for(int i=0; i<index; i++){
	    preNode = removedN;
	    removedN = removedN->next;
	    if(removedN==NULL){
		    return false;
	    }
    }
    if(preNode==NULL){
	    list->first = removedN->next;
	    if(list->first==NULL){
		    list->last=NULL;
	    }
    }else{
	    preNode->next = removedN->next;
	    if(removedN->next==NULL){
		    list->last = preNode;
	    }
    }
    free(removedN);
    list->size--;
    return true;
}

int list_find (list_t *list, int item)
{
    for(int x=0; x<list->size; x++){
	    int get = list_get(list,x);
	    if(get==item){
		    return x;
	}
    }
    return -1;
}

int list_get (list_t *list, int index)
{
   node_t *currentN = list->first;
   if(currentN== NULL)
   {
	   return -1;
   }
   for(int i=0; i< index; i++){
	   currentN = currentN->next;
	   if(currentN==NULL){
		   return -1;
	   }
   }
   return currentN->data;
	
}

