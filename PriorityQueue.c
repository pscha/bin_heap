#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
* 	This library implements a priority queue using a binary heap.
* 	
* 	It was written for a course in compiler construction
* 	at the Humboldt University of Berlin by
* 		Sascha Martensen <martensensascha@gmail->com>
*  		Nikita Rose <gurkenglas@outlook.com>
*/

/*
	define a node structure with parent and child nodes
*/

/****
	Interface functions
****/

/* Construct a wrapper around the root of a (as yet empty) binary heap */
priorityQueue* newPriorityQueue()
{
	priorityQueue* queue = (priorityQueue*) malloc(sizeof(priorityQueue));
	queue->root = NULL;
	queue->size = 0;
	return queue; 
}

/* Construct a binary tree node with given data and insert it into the heap */
priorityQueueEntry priorityQueueInsert(priorityQueue* queue, int key, void* data)
{	
	/* Construction */
	priorityQueueEntry* entry =	(priorityQueueEntry*) malloc(sizeof (priorityQueueEntry));
	entry->key=key;
	entry->data=data;
	entry->parent=NULL;
	entry->childl=NULL;
	entry->childr=NULL;

	/* Insertion */
	queue->size++;
	if(queue->size==1)
		queue->root=entry;
	else {
		/* Find the variable that shall store the new entry */
		priorityQueueEntry* parent=nodeAt(queue, (queue->size)/2);
		priorityQueueEntry* *destination;
		if(queue->size%2==0)
			destination=&(parent->childl);
		else
			destination=&(parent->childr);
		assert(*destination==NULL);
		
		*destination=entry;
		entry->parent=parent;
		promote(entry);
	}
	
	return* entry;
}

/* Decrease an entry's key and update its position */
void priorityQueueDecreaseKey(priorityQueue* queue, priorityQueueEntry* entry, int newKey)
{
	entry->key=newKey;
	promote(entry);
}

/* Drop the root of the binary heap, but return its contents */
void* priorityQueueExtract(priorityQueue* queue)
{
	void* data=queue->root->data;
	priorityQueueEntry* lastentry=nodeAt(queue, queue->size);
	swap(lastentry, queue->root);
	if(lastentry->parent) {
		if(lastentry->parent->childl==lastentry)
			lastentry->parent->childl=NULL;
		else
			lastentry->parent->childr=NULL;
	} else
		queue->root=NULL;
	free(lastentry);
	demote(queue->root);
	queue->size--;
	return data;
}

/* Deallocate the memory assigned to a queue's tree, then its own */
void deletePriorityQueue(priorityQueue* queue)
{
	freeNode(queue->root);
	free(queue);
}


/*****
	non interface functions 
*****/

/* Promote an entry that is suspected to be of lower key than its ancestors up the heap */
void promote(priorityQueueEntry* current) {
	while(current->parent && current->parent->key > current->key) {
		swap(current, current->parent);
		current=current->parent;
	}
}

/* Demote an entry that is suspected to be of higher key than its descendants down the heap */
void demote(priorityQueueEntry* current)
{
	priorityQueueEntry* next=current->childl;
	if(!current)
		return;
	if(!next || (current->childr && current->childr->key < next->key))
		next=current->childr;
	if(!next || next->key >= current->key)
		return;
	swap(current, next);
	demote(next);
}

int reverseInt(int i) {
	int result=1;
	while(i>1) {
		result=result*2+i%2;
		i/=2;
	}
	return result;
}

/* Return that queue's entry which would be its last if the address were its size */
priorityQueueEntry* nodeAt(priorityQueue* queue, int address)
{
	priorityQueueEntry* current=queue->root;
	
	address=reverseInt(address);
	
	while(address!=1) {
		if(address%2==0)
			current = current->childl;
		else
			current = current->childr;
		address/=2;
	}
	
	return current;
}

/* Swap the contents of two entries */
void swap(priorityQueueEntry* entry1, priorityQueueEntry* entry2)
{
	int keyTmp = entry1->key;
	void* dataTmp = entry1->data;
	entry1->key = entry2->key;
	entry1->data = entry2->data;
	entry2->key = keyTmp;
	entry2->data = dataTmp;
}

/* Recursively deallocate the memory assigned to this node's subtree */
void freeNode(priorityQueueEntry* node)
{
	if(node->childl)
		freeNode(node->childl);
	if(node->childr)
		freeNode(node->childr);
	free(node);	
}

void output(priorityQueueEntry* entry) {
	char* h=(char*)entry->data;
	if(entry==NULL)
		return;
	printf("%s",h);
	printf("%s","(");
	output(entry->childl);
	printf("%s","|");
	output(entry->childr);
	printf("%s",")");
}

/*int main(int argc, char* *argv)
{
	priorityQueue* q=newPriorityQueue();
	printf("hello world\n");
	output(q->root); puts("");
	priorityQueueInsert(q, 2, "a");
	output(q->root); puts("");
	priorityQueueInsert(q, 3, "b");
	output(q->root); puts("");
	priorityQueueInsert(q, 1, "c");
	output(q->root); puts("");
	priorityQueueInsert(q, 4, "d");
	output(q->root); puts("");
	priorityQueueExtract(q);
	output(q->root); puts("");
	priorityQueueExtract(q);
	output(q->root); puts("");
	priorityQueueExtract(q);
	output(q->root); puts("");
	priorityQueueExtract(q);
	output(q->root); puts("");
	printf("hello world\n");
	return 0;
}*/
