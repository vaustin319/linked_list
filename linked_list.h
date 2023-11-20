#include <stdio.h>
#include <stdint.h>

/* Linked list node structure */
struct node {
    int value;
    struct node* next;

};

/* Insert a node at a given index */
void insert(struct node** head, int value, int index);

/* Remove a node at a given index */
void remove_at_index(struct node** head, int index);

/* Remove all nodes with a given value */
void remove_with_value(struct node** head, int value);

/* Returns the node at the given index, or NULL */
struct node* find_at_index(struct node* head, int index);

/* Returns a node with the given value, or NULL */
struct node* find_with_value(struct node* head, int value);

/* Returns a node with the smallest value in the linked list */
struct node* find_smallest(struct node* head);

/* Returns a node with the largest value in the linked list */
struct node* find_largest(struct node* head);

/* Returns the node with the next smallest value in the linked list */
struct node* find_next_smallest(struct node* head, int value);

/* Returns the node with the next largest value in the linked list */
struct node* find_next_largest(struct node* head, int value);

/* Prints the elements of the linked list */
void print_list(struct node* head);

/* Counts the length of the linked list */
size_t length(struct node* head);

/* Counts the number of nodes with a given value */
int value_count(struct node* head, int value);

/* Helper that returns the prev node of the target node */
struct node* get_prev(struct node* head, struct node* target);

/* Frees the memory allocated for the linked list */
void free_list(struct node* head);

/* Sorts the nodes in the list in ascending or decending order
using merge sort*/
void sort_list(struct node** head, uint8_t ascending);