#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "stack.h"
#include "linkedList.h"

int main(void) {
  printf("----- [ QUEUE ] -----\n");
  queue_t* queue = createQueue();
  // Enqueue
  for (int index = 0; index < 5; index ++) {
    enqueue(queue, index);
  }
  printQueue(queue);
  // Peek
  int value = queuePeek(queue);
  if (value == 0) {
    printf("PEEK - SUCCESS\n");
  } else {
    printf("PEEK = FAIL\n");
  }
  // Dequeue
  for (int index = 0; index < 5; index ++) {
    int value = dequeue(queue);
    if (index == value) {
      printf("DEQUEUE - SUCCESS: %d\n", index);
    } else {
      printf("DEQUEUE - FAIL: %d\n", index);
    }
  }
  if (queueIsEmpty(queue)) {
    printf("EMPTY - SUCCESS\n");
  } else {
    printf("EMPTY - FAIL\n");
  }
  // Free the memory
  freeQueue(queue);
  printf("----- [ STACK ] -----\n");
  stack_t* stack = createStack();
  for (int index = 0; index < 5; index ++) {
    stackPush(stack, index);
  }
  freeStack(stack);
  printf("----- [ LINKED_LIST ] -----\n");
  linkedList_t* linkedList = createList();
  for (int index = 0; index < 5; index ++) {
    listPush(linkedList, index);
  }
  // Free the memory
  freeList(linkedList);
	return 0;
}
