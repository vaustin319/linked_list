#include "../linked_list.h"
#include <assert.h>
#include <stdlib.h>


void test_insert(struct node** head, int value ) {
    /* Check that an element can be inserted */
    insert(head, value, 1);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->next->value == value);
    assert((*head)->next->next == NULL);

    /* Check that an element can be inserted at the beginning */
    int new_value = 64;
    insert(head, new_value, 0);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->value == new_value);
    assert((*head)->next->next->next == NULL);

    /* Check that an invalid index does not corrupt the list */
    insert(head, new_value, 7);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->value == new_value);
    assert((*head)->next->next->next == NULL);
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