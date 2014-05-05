#include "PriorityQueue.h"
#include <stdlib.h>

/*
	define a node structure with parent and child nodes
*/

struct priorityQueueEntry {
	struct priorityQueueEntry parent;
	struct priorityQueueEntry childl;
	struct priorityQueueEntry childr;
	int key;
	void *data;
}

/****
	Interface functions
****/
priorityQueue * newPrioroityQueue(){
	
/* 
	generate a pointer to the position the first node is 
	going to be
*/	

	struct priorityQueueEntry *queueStartPointer;

	return *queueStartPointer; 
	
}

priorityQueueEntry priorityQueueInsert(\	
	priorityQueue* queue, \
	int key,\
	void* data){

/*
	generate an entry, pass all the data into it
	and get it into the right position
*/
	
	/* allocate memory */
	priorityQueueEntry entry = \
		(struct priorityQueueEntry *)\
		malloc(sizeof (struct priorityQueueEntry));

	/* move information into the entrys */
	entry.key=key;
	entry.data=data;
	entry.childl=NULL;
	entry.childr=NULL;
	entry.parent=
	/* get the entry into the corect position */
	heapify();	
}


/*****
	non interface functions 
*****/

heapify(){

}

swap(priorityQueueEntry entry1, priorityQueueEntry entry2){
	keyTmp = entry1.
}


