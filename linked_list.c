#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

Node * make_node(int32_t data) { 
    // Create and return node struct 
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

LinkedList * make_list(Node * e) { 
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

Node * add_first(Node * e, LinkedList * l) { 
    // Add to the front of the LL and return the added node 
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
    e->next = current_front;
    l->head = e;
    return e;
}

Node * add_last(Node * e, LinkedList * l) { 
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
    l->tail = e;
    return e;
}

Node * remove_first(LinkedList * l) { 
    if (l == NULL) { 
        return NULL;
    } 
    Node * current_head = l->head;
    if (current_head == NULL) { 
        // According to the specs, cannot remove from an empty list 
        fprintf(stderr, "Cannot remove_first from an empty list!\n");
        exit(ERROR);
    } else { 
        Node * next_head = current_head->next;
        // Make the LL inaccessible to the removed node 
        current_head->next = NULL;
        l->head = next_head;
        l->length--;
        if (next_head == NULL) { 
            // Set the tail to NULL when removing the last element 
            l->tail = NULL;
        }
        return current_head;
    }
}

Node * remove_last(LinkedList * l) { 
    if (l == NULL) { 
        return NULL;
    } 
    Node * current_tail = l->tail;
    if (current_tail == NULL) { 
        fprintf(stderr, "Cannot remove_first from an empty list!\n");
        exit(ERROR);
    } else { 
        Node * next_tail = get_second_last(l);
        l->tail = next_tail;
        l->length--;
        if (next_tail != NULL) { 
            next_tail->next = NULL;
        } else { 
            // Set the head to NULL when removing the last element 
            l->head = NULL;
        }
        return current_tail;
    }
}

Node * get_first(LinkedList * l) { 
    if (l == NULL) { 
        return NULL;
    }
    return l->head;
}

Node * get_last(LinkedList * l) { 
    // O(1) implementation due to the pointer to the linked list's tail
    if (l == NULL) { 
        return NULL;
    }
    return l->tail;
}

Node * get_second_last(LinkedList * l) {
    // Gets the second last node in a linked list (if it exists). Due to being 
    // singly linked, we must traverse until the second last element: O(n)
    if (l == NULL || l->head == NULL || l->head->next == NULL) { 
        return NULL;
    }
    Node * second_last = l->head;
    while (second_last->next->next != NULL) { 
        second_last = second_last->next;
    }
    return second_last;
}

void show_list(LinkedList * l) { 
    if (l == NULL || l->head == NULL) { 
        return;
    }
    // Iterate until the second last element
    Node * current_node = l->head;
    for (int i = 0; i < l->length - 1; i++) { 
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    // Print the last element without an arrow 
    printf("%d\n", current_node->data);

}

void reverse_list(LinkedList *l) { 
    // Reverses a singly linked list in O(n) using three cursors  
    if (l == NULL || l->length == 0 || l->length == 1) { 
        return;
    }
    Node * previous = NULL;
    Node * current = l->head;
    Node * tail = l->head; // Temp var for a tail reference
    Node * next = NULL;
    while (current != NULL) { 
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    l->head = previous;
    l->tail = tail;
}

void free_node(Node * e) { 
    free(e);
}

void free_list(LinkedList * l) { 
    // Free all the nodes in the list, then free the list itself 
    Node * current_node = l->head;
    while (current_node != NULL) { 
        Node * next_node = current_node->next;
        free_node(current_node);
        current_node = next_node;
    }
    free(l);
}