#include "PriorityQueue.c"


int main(){

	
	priorityQueue* root = newPriorityQueue();
	int integer = 12;
	float fliesskomma = 12.12;
	void* string = "HALLO";
	void* integerp = &integer ;
	void* stringTwo = "Welt";
	void* fliesskommap = &fliesskomma;

	priorityQueueEntry entry3= priorityQueueInsert(root, 4, stringTwo);
	priorityQueueInsert(root, 5, fliesskommap);
	priorityQueueInsert(root, 1, string);
	priorityQueueInsert(root, 3, integerp);

	priorityQueueDecreaseKey(root, &entry3,2);
	
	printf("%s %s %d %f", \
		(char*) priorityQueueExtract(root),\
		(char*) priorityQueueExtract(root),\
		(int) priorityQueueExtract(root),\
		(double) priorityQueueExtract(root)\
	);
	
	entry3 = priorityQueueInsert(root, 1, string);
	
	deletePriorityQueue(root);

	return 0;
}
