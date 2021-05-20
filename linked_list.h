#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdint.h>

/* Define both a linked list and node struct. The linked list contains 
information about the state of the list (for better time complexity retrieval), 
and the list is singly-linked as in the specs.
*/ 

#define ERROR 1

typedef struct node Node;
typedef struct linkedlist LinkedList;
typedef struct node { 
    // Pointer to the next node
    Node * next;
    int32_t data;
} Node;

typedef struct linkedlist { 
    // Pointer to the head and tail nodes of the list
    Node * head;
    Node * tail;
    int length;
} LinkedList;

Node * make_node(int32_t data);
LinkedList * make_list(Node * e);
Node * add_first(Node * e, LinkedList * l);
Node * add_last(Node * e, LinkedList * l);
Node * remove_first(LinkedList * l);
Node * remove_last(LinkedList * l);
Node * get_first(LinkedList * l);
Node * get_last(LinkedList * l);
Node * get_second_last(LinkedList * l);
void show_list(LinkedList * l);
void free_node(Node * e);
void free_list(LinkedList * l);
void reverse_list(LinkedList *l);
#endif
