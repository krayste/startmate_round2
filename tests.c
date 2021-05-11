#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
#include "tests.h"

/*
Startmate Round 2 Task. 
Author: Steve Kraynov 
*/

int main() { 

    /*
    Testing positive/negative/edge cases for linked list functionality. Note 
    that the removeFoo() functions remove a node from the list, but it is still
    allocated in memory. It is the programmer's job to freeNode() on these 
    nodes. Stricter testing in future should be done using a testing framework
    such as CMocka
    */
    LinkedList * linked_list_1 = makeList(NULL);
    
    // Cannot add a NULL reference to a linked list  
    addFirst(NULL, linked_list_1); 
    showList(linked_list_1); // No output 

    // Add some nodes to the front 
    addFirst(makeNode(1), linked_list_1); 
    addFirst(makeNode(2), linked_list_1); 
    addFirst(makeNode(3), linked_list_1); 
    addFirst(makeNode(4), linked_list_1); 
    showList(linked_list_1); // 4 -> 3 -> 2 -> 1

    // Add some nodes to the back 
    addLast(makeNode(5), linked_list_1); 
    addLast(makeNode(6), linked_list_1); 
    addLast(makeNode(7), linked_list_1); 
    addLast(makeNode(8), linked_list_1); 
    showList(linked_list_1); // 4 -> 3 -> 2 -> 1 -> 5 -> 6 -> 7 -> 8

    // Remove nodes from the front 
    freeNode(removeFirst(linked_list_1)); 
    freeNode(removeFirst(linked_list_1)); 
    freeNode(removeFirst(linked_list_1)); 
    freeNode(removeFirst(linked_list_1)); 
    showList(linked_list_1); // 5 -> 6 -> 7 -> 8

    // Remove some nodes from the back 
    freeNode(removeLast(linked_list_1)); 
    freeNode(removeLast(linked_list_1)); 
    freeNode(removeLast(linked_list_1)); 
    showList(linked_list_1); // 5

    // Edge cases: Removing the first and last of a one element linked list 
    freeNode(removeFirst(linked_list_1)); 
    showList(linked_list_1); // No output

    addFirst(makeNode(1), linked_list_1); 
    freeNode(removeLast(linked_list_1)); 
    showList(linked_list_1); // No output

    // Negative case: Removing from an empty list 
    freeNode(removeFirst(linked_list_1)); 
    showList(linked_list_1); // No output
    freeNode(removeLast(linked_list_1)); 
    showList(linked_list_1); // No output

    // Testing getting the first and last elements of the linked list 
    assert(getFirst(linked_list_1) == NULL);
    assert(getLast(linked_list_1) == NULL);
    addFirst(makeNode(1), linked_list_1); 
    assert(getFirst(linked_list_1)->data == 1);
    assert(getLast(linked_list_1)->data == 1);
    addFirst(makeNode(2), linked_list_1); 
    assert(getFirst(linked_list_1)->data == 2);
    assert(getLast(linked_list_1)->data == 1);
}

