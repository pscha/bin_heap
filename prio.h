#ifndef PRIO_H
#define PRIO_H

/* define an priorityQueueEntry */
struct priorityQueueEntry{
        struct priorityQueueEntry* parent;
        struct priorityQueueEntry* child;
        void* data;
        int key;
};

typedef struct priorityQueueEntry priorityQueueEntry;

/* define a priorityQueue as the initial entry */
struct priorityQueue{
        priorityQueueEntry root;
	int size;
};

typedef struct priorityQueue priorityQueue;


priorityQueue* newPriorityQueue();

#endif
