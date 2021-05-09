#ifndef QUEUE_H
#define QUEUE_H

// Node in the queue
struct queueNode {
	int data;
	struct queueNode* next;
};

typedef struct queueNode queueNode_t;

// Stores the head node
typedef struct {
  queueNode_t* head;
  queueNode_t* tail;
} queue_t; 

// Creates a new queue
queue_t* createQueue();

// Enqueues data to the queue
void enqueue(queue_t* queue, int data);

// Dequeues data from the queue
int dequeue(queue_t* q);

// Returns the first data in the array
int queuePeek(queue_t* queue);

// Returns 1 if the queue is empty, or 0
int queueIsEmpty(queue_t* queue);

// PrintQueue
void printQueue(queue_t* queue);

// Free the memory
void freeQueue(queue_t* queue);

#endif