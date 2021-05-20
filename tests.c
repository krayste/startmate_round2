#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

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
    LinkedList * linked_list_1 = make_list(NULL);
    
    /* Cannot add a NULL reference to a linked list */
    add_first(NULL, linked_list_1); 
    show_list(linked_list_1); // No output 

    /* Add some nodes to the front */
    add_first(make_node(1), linked_list_1); 
    add_first(make_node(2), linked_list_1); 
    add_first(make_node(3), linked_list_1); 
    add_first(make_node(4), linked_list_1); 
    show_list(linked_list_1); // 4 -> 3 -> 2 -> 1

    /* Add some nodes to the back */
    add_last(make_node(5), linked_list_1); 
    add_last(make_node(6), linked_list_1); 
    add_last(make_node(7), linked_list_1); 
    add_last(make_node(8), linked_list_1); 
    show_list(linked_list_1); // 4 -> 3 -> 2 -> 1 -> 5 -> 6 -> 7 -> 8

    /* Remove nodes from the front */
    free_node(remove_first(linked_list_1)); 
    free_node(remove_first(linked_list_1)); 
    free_node(remove_first(linked_list_1)); 
    free_node(remove_first(linked_list_1)); 
    show_list(linked_list_1); // 5 -> 6 -> 7 -> 8

    /* Remove some nodes from the back */
    free_node(remove_last(linked_list_1)); 
    free_node(remove_last(linked_list_1)); 
    free_node(remove_last(linked_list_1)); 
    show_list(linked_list_1); // 5

    /* Edge cases: Removing the first and last of a one element linked list */
    free_node(remove_first(linked_list_1)); 
    show_list(linked_list_1); // No output
    add_first(make_node(1), linked_list_1); 
    free_node(remove_last(linked_list_1)); 
    show_list(linked_list_1); // No output

    /* Negative case: Removing from an empty list will throw an error. 
    Uncomment these lines then compile to demonstrate. */
    // free_node(remove_first(linked_list_1)); 
    // show_list(linked_list_1);
    // free_node(remove_last(linked_list_1)); 
    // show_list(linked_list_1);

    /* Testing getting the first and last elements of the linked list */
    assert(get_first(linked_list_1) == NULL); // Empty lists should return NULL
    assert(get_last(linked_list_1) == NULL); // Empty lists should return NULL
    add_first(make_node(1), linked_list_1); 
    assert(get_first(linked_list_1)->data == 1); // Checking for correct data 
    assert(get_last(linked_list_1)->data == 1); // Checking for correct data 
    add_first(make_node(2), linked_list_1); 
    assert(get_first(linked_list_1)->data == 2); // Checking for correct data 
    assert(get_last(linked_list_1)->data == 1); // Checking for correct data 
    
    free_list(linked_list_1);
    return 0;
}

