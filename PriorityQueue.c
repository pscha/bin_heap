#include <stdlib.h>

/*
	define a node structure with parent and child nodes
*/

struct priorityQueueEntry {
	struct priorityQueueEntry* childl;
	struct priorityQueueEntry* childr;
	int key;
	void *data;
};
typedef struct priorityQueueEntry priorityQueueEntry;


typedef struct priorityQueue{
	struct priorityQueueEntry* root;
	int size;
};

typedef struct priorityQueue priorityQueue;

/****
	Interface functions
****/
priorityQueue* newPrioroityQueue(){
	
/* 
	generate a pointer to the position the first node is 
	going to be
*/	

	priorityQueue *queue;
	(*queue).root = NULL;
	(*queue).size = 0;
	
	return queue; 
	
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
		malloc(sizeof (priorityQueueEntry));

	/* move information into the entrys */
	entry.key=key;
	entry.data=data;
	entry.childl=NULL;
	entry.childr=NULL;

	/* get the entry into the corect position */

	if(size==0)
		newchild=*queue.root;
	else {
		int address=reverseInt(size);
		priorityQueueEntry* newchild=trickle(*queue.root, *entry, address);
	}
	*newchild = entry;
	
	return entry;
}




/*****
	non interface functions 
*****/
int reverseInt(int i) {
	int result=1;
	do
		result=result*2+i%2
	while(i/=2>1);
	return result;
}

priorityQueueEntry* trickle(\
	priorityQueueEntry node,\
	priorityQueueEntry entry,\
	int address){
	
	if(*entry.key<*node.key)
		swap(key,entry);
	
	priorityQueueEntry* next;
	if(address%2==0)
		next* =node.childl;
	else
		next* =node.childr;
	address/=2;
	
	if(next)
		return trickle(*next,*entry,address);
	else {
		if(address!=1)
			printf("ADDRESS!=1");
		return next;
	}
}


swap(priorityQueueEntry entry1, priorityQueueEntry entry2){
	int keyTmp = entry1.key;
	void* dataTmp = entry1.data;
	entry1.key = entry2.key;
	entry1.data = entry2.data;
	entry2.key = keyTmp;
	entry2.data = dataTmp;
}


