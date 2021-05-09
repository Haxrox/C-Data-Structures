#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node in the list
struct linkedNode {
    int data;
    struct linkedNode* next;
};

typedef struct linkedNode linkedNode_t;

// Stores the head node
typedef struct {
    linkedNode_t* head;
    int size;
} linkedList_t;

// Creates new linked_list
linkedList_t* createList();

// Insert data at a specified index
void listInsert(linkedList_t* list, int data, int index);

// Inserts data at the head of the list
void listPush(linkedList_t* list, int data);

// Appends data at the end of the list
void listAppend(linkedList_t* list, int data);

// Removes and returns the data at the specified index
int listRemove(linkedList_t* list, int index);

// Gets data at a specific index
int listGet(linkedList_t* list, int index);

// Gets the size of the linkedList_t
int listGetSize(linkedList_t* list);

// Returns 1 if the list is empty, or 0
int listIsEmpty(linkedList_t* list);

// Frees the memory
void freeList(linkedList_t* list);

#endif