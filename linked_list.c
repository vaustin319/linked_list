#include "linked_list.h"
#include <stdlib.h>

/* Insert a node at head postion */
struct node* insert_first(struct node** head, int value) {
    return *head;
}

/* Insert a node at a given index */
void insert(struct node** head, int value, int index) {
    if (index == 0) {
        return;
    }
    struct node* curr = *head;
    struct node* prev = *head;
    struct node* new_node;

    for (int i = 0; curr != NULL; i++) {
        if (index == i) {
            new_node = (struct node*) malloc(sizeof(struct node));
            if (new_node == NULL) {
                return;
            }
            new_node->value = value;
            new_node->next = curr;
            //prev->next = new_node;
        } 
        prev = curr;
        curr = curr->next;
    }
}

/* Remove a node at a given index */
void remove_at_index(struct node** head, int index) {
    return;
}

/* Remove a node with a given value */
void remove_with_value(struct node** head, int value) {
    return;
}

/* Returns the node at the given index, or NULL */
struct node* find_at_index(struct node* head, int index) {
    return head;
}

/* Returns the node with the given value, or NULL */
struct node* find_with_value(struct node* head, int value) {
    return head;
}

/* Returns the node with the smallest value in the linked list */
struct node* find_smallest(struct node* head) {
    return head;
}

/* Returns the node with the largest value in the linked list */
struct node* find_largest(struct node* head) {
    return head;
}

/* Prints the elements of the linked list */
void print_list(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->value);
        curr = curr->next;
    }
}

/* Counts the length of the linked list */
size_t length(struct node* head) {
    return 0;
}

/* Frees the memory allocated for the linked list */
void free_list(struct node* head) {
    return;
}

/* Sorts the nodes in the list in ascending or decending order with quick sort */
void sort_list(struct node** head, uint8_t ascending) {
    return;
}