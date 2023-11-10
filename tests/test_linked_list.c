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

void test_remove_at_index(struct node** head) {
    /* Test we can remove the head of the list */
    int index = 0;
    remove_at_index(head, index);
    assert((*head)->value == 25);
    print_list(*head);

    /* Test we can remove any element from the list */
    index = 1;
    remove_at_index(head, index);
    assert((*head)->value == 25);
    assert((*head)->next == NULL);
    print_list(*head);
}

void test_remove_with_value(struct node**head, int value) {
    /* Remove last value */
    remove_with_value(head, value);
    print_list(*head);
    
    /* Remove first value */
    remove_with_value(head, (*head)->value);
    print_list(*head);
    
    /* Add dup value 25, and then try to remove it. head should be NULL! */
    insert(head, 25, 1);
    print_list(*head);
    remove_with_value(head, (*head)->value);
    assert(*head == NULL);
}

int main(void) {
    int head_value = 25;
    int test_value = 88;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->value = head_value;
    head->next = NULL;
    printf("Testing insertion\n");
    test_insert(&head, test_value);
    //test_remove_at_index(&head);
    printf("Testing remove by value\n");
    test_remove_with_value(&head, test_value);
}