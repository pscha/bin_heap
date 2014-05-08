#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>
/*
 *	A kind of library for priorityqueues
 *	
 *	This was written for courses in building compilers
 *	at university by
 *		Sascha Martensen <martensensascha@gmail.com>
*/

/*
	define a node structure with parent and child nodes
*/
int reverseInt(int);
priorityQueueEntry* trickle(\
        priorityQueueEntry,\
        priorityQueueEntry,\
        int);

void swap(priorityQueueEntry, priorityQueueEntry);

priorityQueueEntry* priorityQueueEntryExtract(
        priorityQueueEntry current
);
void freeNode(priorityQueueEntry*);
/****
	Interface functions
****/
priorityQueue* newPrioroityQueue()
{
	
/* 
	generate a pointer to the position the first node is 
	going to be
*/	

	priorityQueue *queue = (priorityQueue*) malloc(sizeof(priorityQueue));
	(*queue).root = NULL;
	(*queue).size = 0;
	
	return queue; 
	
}

priorityQueueEntry priorityQueueInsert(\
	priorityQueue* queue, \
	int key,\
	void* data)
{

/*
	generate an entry, pass all the data into it
	and get it into the right position
*/
	
	priorityQueueEntry* newchild;
	/* allocate memory */
	priorityQueueEntry* entryp = \
		(priorityQueueEntry *) \
		malloc(sizeof (priorityQueueEntry));

	priorityQueueEntry entry = *entryp;
	/* move information into the entrys */
	entry.key=key;
	entry.data=data;
	entry.parent=NULL;
	entry.childl=NULL;
	entry.childr=NULL;

	/* get the entry into the corect position */

	if((*queue).size==0)
		newchild=(*queue).root;
	else {
		int address=reverseInt((*queue).size);
		newchild=trickle( *((*queue).root), entry, address);
	}
	*newchild = entry;
	
	return entry;
}

void priorityQueueDecreaseKey(\
	priorityQueue* queue, \
	priorityQueueEntry* entry, \
	int newKey)
{
	/* TODO Error handling */
	priorityQueueEntry current=*entry;
	current.key=newKey;
	while(current.parent && (*current.parent).key > current.key) {
		swap(current,*current.parent);
		current=*current.parent;
	}
}

/*TODO: error smashing, as I don't want to destroy the code*/
void* priorityQueueExtract(
	priorityQueue* queue)
{
	priorityQueueEntry* root=(*queue).root;
	(*queue).root=&(priorityQueueEntryExtract((*queue).root));
	
	/* gibt den datapointer zurück, um an die infos zu kommen */
	return root->data;
}

priorityQueueEntry* priorityQueueEntryExtract(
	priorityQueueEntry current)
{
	priorityQueueEntry next, other;
	if((*current.childl).key<(*current.childr).key) {
		next=*current.childl;
		other=*current.childr;
	}
	else {
		next=*current.childr;
		other=*current.childl;
	}
	next.childl=priorityQueueEntryExtract(next);
	next.childr=other;
}
/* delete the queue */
void deletePriorityQueue(\
	priorityQueue* queue)
{
	/* first free all nodes */
	freeNode(queue->root);
	/* then free the queue */
	free(queue);
}


/*****
	non interface functions 
*****/
int reverseInt(int i) {
	int result=1;
	
	do{
		result=result*2+i%2;
	}
	while(i/=2>1);
	
	return result;
}

priorityQueueEntry* trickle(\
	priorityQueueEntry node,\
	priorityQueueEntry entry,\
	int address)
{
	
	priorityQueueEntry *next;
	
	if(entry.key<node.key){
		swap(node,entry);
	}
	
	if(address%2==0){
		next = node.childl;
	}
	else{
		next = node.childr;
	}

	address/=2;
	
	if(next){
		return trickle(*next,entry,address);
	}
	else{
		if(address!=1)
			printf("ADDRESS!=1");
		*(entry.parent)=node;
		return next;
	}
}


void swap(priorityQueueEntry entry1, priorityQueueEntry entry2)
{
	/* swapping with a temporary variables */
	int keyTmp = entry1.key;
	void* dataTmp = entry1.data;
	entry1.key = entry2.key;
	entry1.data = entry2.data;
	entry2.key = keyTmp;
	entry2.data = dataTmp;
}

void freeNode(priorityQueueEntry* entry)
{
	/* if there are childs, free them */
	if(entry->childl){
		freeNode(entry->childl);
	}
	if(entry->childr){
		freeNode(entry->childr);
	}
	/* then free the node */
	free(entry);	
}
