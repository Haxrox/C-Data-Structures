#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Creates a new queue
queue_t* createQueue() {
  queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
  if (queue) {
    queue->head = NULL;
  } else {
    printf("ERROR - createQueue: Failed to allocate memory for new queue\n");
  }
  return queue;
}

// Enqueues data to the queue
void enqueue(queue_t* queue, int data) {
  queueNode_t* node = (queueNode_t*) malloc(sizeof(queueNode_t));
  if (node) {
    node->data = data;
    node->next = NULL;
    if (queueIsEmpty(queue)) {
      // Queue is empty, so set the head + tail to the new node
      queue->head = node;
      queue->tail = node;
    } else {
      queue->tail->next = node;
      queue->tail = node;
    }
  } else {
    printf("ERROR - enqueue: Failed to allocate memory for new node\n");
  }
}

// Dequeues data to the queue
// Precondition: queue isn't empty
int dequeue(queue_t* queue) {
  queueNode_t* currentNode = queue->head;
  int data = currentNode->data;
  queue->head = currentNode->next;
  if (queue->tail == currentNode) {
    // Removing node was the tail, set the tail to NULL as the queue is not empty
    queue->tail = NULL;
  }
  free(currentNode);
  return data;
}

// Returns the first data in the queue
// Precondition: queue isn't empty
int queuePeek(queue_t* queue) {
  return queue->head->data;
}

// Return 1 if the queue is empty, or 0
int queueIsEmpty(queue_t* queue) {
    return (queue->head == NULL);
}

void printQueue(queue_t* queue) {
  printf("Queue: [");
  queueNode_t* currentNode = queue->head;
  while (currentNode) {
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }
  printf("]\n");
}

// Free the memory
void freeQueue(queue_t* queue) {
    while (!queueIsEmpty(queue)) {
      dequeue(queue);
    }
    free(queue);
}
