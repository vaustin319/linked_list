#include "linked_list.h"
#include <stdlib.h>

/* Insert a node at a given index */
void insert(struct node** head, int value, int index) {
    /* Check for invalid index */
    if (index < 0) {
        return;
    }

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    /* Check that malloc was successful */
    if (new_node == NULL) {
        return;
    }
    new_node->value = value;

    if (index == 0) {
        /* Insert at the beginning, update head pointer */
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct node* curr = *head;
    for (int i = 0; curr != NULL; i++) {
        if (i == index - 1) {
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        } 
        curr = curr->next;

        /* Check for invalid index */
        if (curr == NULL && index > i) {
            free(new_node);
            return;
        }
    }
    
}

/* Helper for removing head of linked list */
void remove_head(struct node** head) {
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

/* Remove a node at a given index */
void remove_at_index(struct node** head, int index) {
    /* Check for invalid index */
    if (index < 0) {
        return;
    }

    /* Check if we are removing the head */
    if (index == 0) {
        remove_head(head);
        return;
    }

    struct node* curr = *head;
    struct node* prev = NULL;
    int i = 0;

    while (curr != NULL && i < index) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    /* Index is in bouds */
    if (index == i && curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

/* Remove all nodes with a given value */
void remove_with_value(struct node** head, int value) {
    struct node* curr = *head;
    struct node* prev = NULL;

    while(curr != NULL) {
        if (curr->value == value) {
            /* Check if we are removing the head */
            if (prev == NULL) {
                remove_head(&curr);
                *head = curr;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
}

/* Returns the node at the given index, or NULL */
struct node* find_at_index(struct node* head, int index) {
    return head;
}

/* Returns a node with the given value, or NULL */
struct node* find_with_value(struct node* head, int value) {
    return head;
}

/* Returns a node with the smallest value in the linked list */
struct node* find_smallest(struct node* head) {
    return head;
}

/* Returns a node with the largest value in the linked list */
struct node* find_largest(struct node* head) {
    return head;
}

/* Prints the elements of the linked list */
void print_list(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/* Counts the length of the linked list */
size_t length(struct node* head) {
    return 0;
}

/* Counts the number of nodes with a given value */
int value_count(struct node* head, int value) {
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