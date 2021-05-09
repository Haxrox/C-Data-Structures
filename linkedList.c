#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

// Creates new linked_list
linkedList_t* createList() {
    linkedList_t* list = (linkedList_t*) malloc(sizeof(linkedList_t)));
    if (list) {
        list->head = NULL;
        list->size = 0;
    } else {
        printf("ERROR - createList: Failed to allocate memory for linked list\n");
    }
    return list;
}

// Inserts data at the head of the list
void listPush(linkedList_t* list, int data) {
    linkedNode_t* node = (linkedNode_t*) malloc(sizeof(linkedNode_t));
    if (node) {
        node->data = data;
        node->next = list->head;
        list->head = node;
        // increment the size variable
        list->size ++;
    } else {
        printf("ERROR - listPush: Failed to allocate memory for new node\n");
    }
}

// Insert data at a specified index
void listInsert(linkedList_t* list, int data, int index) {
    if (index < list->size) {
        linkedNode_t* node = (linkedNode_t*) malloc(sizeof(linkedNode_t));
        if (node) {
            node->data = data;
            if (index <= 0) {
                // Inserting head
                node->next = list->head;
                list->head = node;
            } else {
                int currentIndex = 0;
                linkedNode_t* currentNode = list->head;
                // loop until we get the node before the index
                while (currentIndex < (index - 1)) {
                    currentNode = currentNode->next;
                    currentIndex++;
                }
                // insert the node at the index
                node->next = currentNode->next;
                currentNode->next = node;
            }           
            // increment the size
            list->size++;
        } else {
            printf("ERROR - listInsert: Failed to allocate memory for new node\n");
        }
    } else {
        printf("ERROR - listInsert: Inserting index > list->size (%d > %d)\n", index, list->size);
    }
}

// Appends data at the end of the list
void listAppend(linkedList_t* list, int data) {
    linkedNode_t* node = (linkedNode_t*) malloc(sizeof(linkedNode_t));
    if (node) {
        // list is empty, so the head is the end of the list
        if (listIsEmpty(list)) {
            list->head = node;
        } else {
            linkedNode_t* currentNode = list->head;
            // loop until we reach the end
            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            } 
        }
        // configure the node
        node->data = data;
        node->next = NULL;
        currentNode->next = node;
        // increment the size
        list->size++;
    } else {
        printf("ERROR - listAppend: Failed to allocate memory for new node\n");
    }
}

// Removes and returns the data at the specified index
// Precondition: list isn't empty && index < list->size
int listRemove(linkedList_t* list, int index) {
    linkedNode_t* currentNode = list->head;
    int data = currentNode->data;
    // remove the first element in the list (the head element)
    if (index == 0) {
        list->head = currentNode->next;
        free(currentNode);
    } else {
        int currentIndex = 0;
        // loop until we get the node before the index
        while (currentIndex < (index - 1)) {
            currentNode = currentNode->next;
            currentIndex++;
        }
        data = currentNode->next->data;
        // set the previous node to the node right after the node at the specified index
        currentNode->next = currentNode->next->next;
        // free the node at the specified index
        free(currentNode->next);
    }
    // decrement the size
    list->size--;
    // list is empty
    if (list->size < 0) {
        list->size = 0;
    }
    return data;
}

// Gets data at a specific index
// Precondition: list isn't emtpy and index < list->size
int listGet(linkedList_t* list, int index) {
    int currentIndex = 0;
    linkedNode_t* currentNode = list->head;
    // loop until we reach the specified index
    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }
    data = currentNode->data;
    return data;
}

// Gets the size of the linkedList_t
int listGetSize(linkedList_t* list) {
    return list->size;
}

// Returns 1 if the list is empty, or 0
int listIsEmpty(linkedList_t* list) {
    return (list->head == NULL || list->size == 0);    
}

// Frees the memory
void freeList(linkedList_t* list) {
    while(!listIsEmpty(list)) {
        listRemove(list, 1);
    }
    free(list);
}