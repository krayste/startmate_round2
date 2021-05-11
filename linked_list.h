#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdint.h>

/* Define both a linked list and node struct. The linked list contains 
information about the state of the list (for better time complexity retrieval), 
and the list will be implemented as a doubly-linked list for future 
expandabiility.
*/ 

typedef struct node Node;
typedef struct linkedlist LinkedList;
typedef struct node { 
    // Pointer to the next and previous nodes
    Node * next;
    Node * previous;
    int32_t data;
} Node;

typedef struct linkedlist { 
    // Pointer to the head and tail nodes of the list
    Node * head;
    Node * tail;
    int length;
} LinkedList;

Node * makeNode(int32_t data);
LinkedList * makeList(Node * e);
Node * addFirst(Node * e, LinkedList * l);
Node * addLast(Node * e, LinkedList * l);
Node * removeFirst(LinkedList * l);
Node * removeLast(LinkedList * l);
Node * getFirst(LinkedList * l);
Node * getLast(LinkedList * l);
void showList(LinkedList * l);
void freeNode(Node * e);
void freeList(LinkedList * l);
#endif
