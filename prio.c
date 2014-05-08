#include <stdlib.h>
#include "prio.h"
/*
	A binary min heap implemented as a heapyfied array
*/

/* define an priorityQueueEntry */
/*struct priorityQueueEntry{
	struct priorityQueueEntry parent;
	struct priorityQueueEntry child;
	void* data;
	int key;
};

typedef struct priorityQueueEntry priorityQueueEntry;
*/
/* define a priorityQueue as the initial entry */
/*struct priorityQueue{
	priorityQueueEntry root;
};

typedef struct priorityQueue priorityQueue;
*/
priorityQueue* newPriorityQueue(){
	
        priorityQueue *queue = malloc(sizeof(priorityQueue));

        return queue;
}

priorityQueueEntry priorityQueueEntryInsert(\
	priorityQueue* queue,\
	int key,\
	void* data\
){
	/* find the first node in queue */
	priorityQueueEntry* target = &queue->root;
	/* create entry */
	priorityQueueEntry* entry = malloc(sizeof(priorityQueueEntry));
	/* populate entry */
	entry->child = NULL;
	entry->key = key;
	entry->data = data;
		
	/* as long as a child node is definded be that child node */
	while(target->child){
		target=target->child;
	}
	
	target->child = entry;
	queue->size++;

	/* remove entropy from heap */
	heapify(queue);

	return(*entry);
}



heapify(\
	priorityQueueEntry* root\
){	
	int smallest = root.key;
	if(smallest < (*root.childl).key)
	
}

