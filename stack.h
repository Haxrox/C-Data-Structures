#ifndef STACK_H
#define STACK_H

struct stackNode {
	int data;
	struct stackNode_t* previous;
	struct stackNode* next;
};

typedef struct stackNode stackNode_t;

typedef struct {
  stackNode_t* head;
  stackNode_t* tail;
} stack_t; 

// Creates a new stack
stack_t* createStack();

// Pushes a given item to the stack
void stackPush(stack_t* stack, int data);

// Pops the top element from the stack
int stackPop(stack_t* stack);

// Returns 1 if the stack is empty, or 0
int stackIsEmpty(stack_t* stack);

// Free the memory
void freeStack(stack_t* stack);

#endif
