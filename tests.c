#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "tests.h"

int main() { 

    // Run the tests 
    LinkedList * linked_list = makeList(NULL);
    addFirst(makeNode(1), linked_list);
    showList(linked_list);
    addFirst(makeNode(2), linked_list);
    showList(linked_list);
    addFirst(makeNode(3), linked_list);
    showList(linked_list);

    addLast(makeNode(5), linked_list);
    showList(linked_list);

    freeNode(removeFirst(linked_list));
    freeNode(removeFirst(linked_list));

    showList(linked_list);
    freeNode(removeLast(linked_list));
    showList(linked_list);
    freeNode(removeLast(linked_list));
    showList(linked_list);

    freeList(linked_list);



}

