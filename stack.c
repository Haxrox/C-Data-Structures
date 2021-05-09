#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// Creates a new stack
stack_t* createStack() {
  stack_t* stack = (stack_t*) malloc(sizeof(stack_t));
  if (stack) {
    stack->head = NULL;
  } else {
    printf("ERROR - createStack: Failed to allocate memory to create stack\n");
  }
  return stack;
}

// Pushes data to the stack
void stackPush(stack_t* stack, int data) {
  stackNode_t* node = (stackNode_t*) malloc(sizeof(stackNode_t));
  if (node) {
    node->data = data;
    // Stack is empty, set both the head and tail
    if (stackIsEmpty(stack)) {
      stack->head = node;
      stack->tail = node;
      node->previous = NULL;
    } else {
      node->previous = stack->tail;
      stack->tail = node;
    }
    node->next = NULL;
  } else {
    printf("ERROR - stackPush: Failed to allocate memory for new node\n");
  }
}

// Pops the top element from the stack
// Precondition: stack isn't empty
int stackPop(stack_t* stack) {
  // Getting the last pushed element in the stack (tail value)
  stackNode_t* currentNode = stack->tail;
  int data = currentNode->data;
  stack->tail = currentNode->previous;
  // Update the previous node so that the next element is NULL
  if (currentNode->previous != NULL) {
    currentNode->previous->next = NULL;
  }
  free(currentNode);
  return data;
}

// Returns 1 if the stack is empty, or 0
int stackIsEmpty(stack_t* stack) {
    return (stack->head == NULL);
}

// Free the memory
void freeStack(stack_t* stack) {
  while (!stackIsEmpty(stack)) {
    stackPop(stack);
  }
  free(stack);
}