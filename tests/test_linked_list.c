#include "../linked_list.h"
#include <assert.h>
#include <stdlib.h>


void test_insert(struct node** head, int value ) {
    /* Check that an element can be inserted */
    insert(head, value, 1);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->next->value == value);
}

int main(void) {
    int head_value = 25;
    int test_value = 88;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->value = head_value;
    head->next = NULL;
    test_insert(&head, test_value);
    free(head->next);
    free(head);
}