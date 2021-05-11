#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Node * makeNode(int32_t data) { 
    // Create and return node struct 
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->previous = NULL;
    node->data = data;
    return node;
}

LinkedList * makeList(Node * e) { 
    // Create and return a linked list struct
    LinkedList * linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    // If initialising an empty linked list, set length to zero 
    if (e == NULL) { 
        linked_list->length = 0;
    } else { 
        linked_list->length = 1;
    }
    linked_list->head = e;
    linked_list->tail = e;
    return linked_list;
}

Node * addFirst(Node * e, LinkedList * l) { 
    // Defensive checks 
    if (e == NULL || l == NULL) { 
        return NULL;
    }

    l->length++;
    Node * current_front = l->head;
    // If the list is empty, just add the node as the head and tail and return
    if (current_front == NULL) { 
        l->head = e;
        l->tail = e;
        return e;
    }
    // Otherwise, set the new node as the head and link it to the previous head
    current_front->previous = e;
    e->next = current_front;
    l->head = e;
    return e;
}

Node * addLast(Node * e, LinkedList * l) { 
    // Defensive checks 
    if (e == NULL || l == NULL) { 
        return NULL;
    }
    l->length++;
    Node * current_end = l->tail;
    if (current_end == NULL) { 
        l->head = e;
        l->tail = e;
        return e;
    }
    current_end->next = e;
    e->previous = current_end;
    l->tail = e;
    return e;
}

Node * removeFirst(LinkedList * l) { 
    // Returns a reference to the removed node. It is up to the programmer
    // to free this node to avoid memory leaks
    if (l == NULL) { 
        return NULL;
    } 
    Node * current_head = l->head;
    if (current_head == NULL) { 
        return NULL;
    } else { 
        Node * next_head = current_head->next;
        // Make the list inaccessible to the removed node 
        current_head->next = NULL;
        l->head = next_head;
        l->length--;
        if (next_head != NULL) { 
            next_head->previous = NULL;
        }
        return current_head;
    }
}

Node * removeLast(LinkedList * l) { 
    // Returns a reference to the removed node. It is up to the programmer
    // to free this node to avoid memory leaks
    if (l == NULL) { 
        return NULL;
    } 
    Node * current_tail = l->tail;
    if (current_tail == NULL) { 
        return NULL;
    } else { 
        Node * next_tail = current_tail->previous;
        // Make the list inaccessible to the removed node 
        current_tail->previous = NULL;
        l->tail = next_tail;
        l->length--;
        if (next_tail != NULL) { 
            next_tail->next = NULL;
        }
        return current_tail;
    }
}



void showList(LinkedList * l) { 
    // Basic defensive checks 
    if (l == NULL || l->head == NULL) { 
        return;
    }

    // Iterate until the second last element
    Node * current_node = l->head;
    for (int i = 0; i < l->length - 1; i++) { 
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }

    // Print the last element without an arrow 
    printf("%d\n", current_node->data);

}

void freeNode(Node * e) { 
    free(e);
}

void freeList(LinkedList * l) { 
    // First free all the nodes in the list, then free the list itself 
    Node * current_node = l->head;
    while (current_node != NULL) { 
        Node * next_node = current_node->next;
        freeNode(current_node);
        current_node = next_node;
    }
    free(l);
}