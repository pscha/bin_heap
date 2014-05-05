priorityQueue* newPriorityQueue()

priorityQueueEntry priorityQueueInsert(priorityQueue* queue, int key, void* data)

void priorityQueueDecreaseKey(priorityQueue* queue, priorityQueueEntry* entry, int newKey)

void* priorityQueueExtract(priorityQueue* queue)

void deletePriorityQueue(priorityQueue* queue)

