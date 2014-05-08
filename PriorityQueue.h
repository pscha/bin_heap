#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "PriorityQueue.c"
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

priorityQueue* newPriorityQueue();

priorityQueueEntry priorityQueueInsert(priorityQueue* queue, int key, void* data);

void priorityQueueDecreaseKey(priorityQueue* queue, priorityQueueEntry* entry, int newKey);

void* priorityQueueExtract(priorityQueue* queue);

void deletePriorityQueue(priorityQueue* queue);
#endif
