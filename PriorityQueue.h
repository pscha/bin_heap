#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
struct priorityQueueEntry {
        struct priorityQueueEntry* parent;
        struct priorityQueueEntry* childl;
        struct priorityQueueEntry* childr;
        int key;
        void *data;
};
typedef struct priorityQueueEntry priorityQueueEntry;

struct priorityQueue{
        struct priorityQueueEntry* root;
        int size;
};
typedef struct priorityQueue priorityQueue;



int reverseInt(int);

priorityQueueEntry* insert(priorityQueueEntry*, priorityQueueEntry*, int);

void swap(priorityQueueEntry*, priorityQueueEntry*);

priorityQueueEntry* priorityQueueEntryExtract(
        priorityQueueEntry *current
);

void freeNode(priorityQueueEntry*);

priorityQueue* newPriorityQueue();

priorityQueueEntry priorityQueueInsert(priorityQueue* queue, int key, void* data);

void priorityQueueDecreaseKey(priorityQueue* queue, priorityQueueEntry* entry, int newKey);

void* priorityQueueExtract(priorityQueue* queue);

void deletePriorityQueue(priorityQueue* queue);

void promote(priorityQueueEntry*);
void demote(priorityQueueEntry*);

priorityQueueEntry* nodeAt(priorityQueue*, int);

#include "PriorityQueue.c"
#endif
