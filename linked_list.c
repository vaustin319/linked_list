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
                /* Reset head pointer */
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
    if (index < 0) {
        return NULL;
    }

    struct node* curr = head;
    for (int i = 0; i <= index && curr != NULL; i++) {
        if (i == index) {
            return curr;
        }
        curr = curr->next;
    }
    return curr;
}

/* Returns a node with the given value, or NULL */
struct node* find_with_value(struct node* head, int value) {
    struct node* curr = head;
    while (curr != NULL) {
        if (curr->value == value) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

/* Returns a node with the smallest value in the linked list */
struct node* find_smallest(struct node* head) {
    struct node* curr = head;
    struct node* smallest = head;
    while (curr != NULL) {
        if(curr->value < smallest->value) {
            smallest = curr;
        }
        curr = curr->next;
    }
    return smallest;
}

/* Returns a node with the largest value in the linked list */
struct node* find_largest(struct node* head) {
    struct node* curr = head;
    struct node* largest = head;
    while (curr != NULL) {
        if(curr->value > largest->value) {
            largest = curr;
        }
        curr = curr->next;
    }
    return largest;
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
    size_t len = 0;
    struct node* curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

/* Counts the number of nodes with a given value */
int value_count(struct node* head, int value) {
    struct node* curr = head;
    int count = 0;
    while (curr != NULL) {
        if (curr->value == value) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

/* Frees the memory allocated for the linked list */
void free_list(struct node* head) {
    struct node* curr = head;
    struct node* temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

/* Returns the node with the next smallest value in the linked list. 
Returns NULL if the given value is the smallest */
struct node* find_next_smallest(struct node* head, int value) {
    struct node* curr = head;
    struct node* next_smallest = NULL;
    while (curr != NULL) {
        if(curr->value < value && (next_smallest == NULL || curr->value >= next_smallest->value)) {
            next_smallest = curr;
        }
        curr = curr->next;
    }

    return next_smallest;
}

/* Returns the node with the next largest value in the linked list.
Returns NULL if the given value is the largest */
struct node* find_next_largest(struct node* head, int value) {
    struct node* curr = head;
    struct node* next_largest = NULL;
    while (curr != NULL) {
        if(curr->value > value && (next_largest == NULL || curr->value <= next_largest->value)) {
            next_largest = curr;
        }
        curr = curr->next;
    }

    return next_largest;
}

/* Helper that returns the prev node of the target node */
struct node* get_prev(struct node* head, struct node* target) {
    struct node* prev = NULL;
    struct node* curr = head;
    while (curr != NULL) {
        if (curr == target) {
            return prev;
        }
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

/* Helper to merge two portions on a linked list in ascending or descending order. */
struct node* merge(struct node* a, struct node* b, uint8_t ascending) {
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    struct node* result = NULL;

    if (ascending == 0) {
        if (a->value >= b->value) {
            result = a;
            result->next = merge(a->next, b, ascending);
        } else {
            result = b;
            result->next = merge(b->next, a, ascending);
        }
    } else {
        if (a->value <= b->value) {
            result = a;
            result->next = merge(a->next, b, ascending);
        } else {
            result = b;
            result->next = merge(b->next, a, ascending);
        }
    }
    return result;
}

/* Helper to split a linked list down the middle. Front is the head and back
is the midpoint. */
void split_list(struct node* head, struct node** front, struct node** back) {
    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
        return;
    }
    
    struct node* fast = head->next;
    struct node* slow = head;

    /* fast moves two nodes at a time and slow moves one */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    /* slow is the midpoint, split the list down the middle */
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

/* Sorts the nodes in the list in ascending or decending order 
using merge sort */
void sort_list(struct node** head, uint8_t ascending) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct node* a;
    struct node* b;

    /* Split linked list in half */
    split_list(*head, &a, &b);

    /* Recursively split and sort list */
    sort_list(&a, ascending);
    sort_list(&b, ascending);

    /* Merge sorted halves */
    *head = merge(a, b, ascending);
}
