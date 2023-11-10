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

    printf("test_insert pass\n");
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
    assert((*head)->next->value == 88);
    print_list(*head);

    printf("test_remove_at_index pass\n");
}

void test_remove_with_value(struct node** head, int value) {
    /* Remove last value */
    remove_with_value(head, value);
    print_list(*head);
    
    /* Remove first value */
    remove_with_value(head, (*head)->value);
    print_list(*head);
    
    /* Add dup value 25, and then try to remove it. head should be NULL! */
    insert(head, 25, 0);
    print_list(*head);
    remove_with_value(head, (*head)->value);
    assert(*head == NULL);

    printf("test_remove_with_value pass\n");
}

void test_find_at_index(struct node* head) {
    /* Check if we get the right value for the given index */
    struct node* result = find_at_index(head, 1);
    assert(result != NULL);
    assert(result->value == head->next->value);

    /* Check that an out of bounds index returns NULL */
    result = find_at_index(head, 40);
    assert(result == NULL);

    printf("test_find_at_index pass\n");
}

void test_find_with_value(struct node* head) {
    /* Check that we get the correct returned value */
    int expected = 25;
    struct node* result = find_with_value(head, expected);
    assert(result != NULL);
    assert(result->value == expected);
    assert(result == head->next);

    /* Check that a value not in the list returns NULL */
    result = find_with_value(head, 400);
    assert(result == NULL);

    printf("test_find_with_value pass\n");
}

void test_length(struct node* head) {
    size_t expected = 3;
    size_t len = length(head);
    assert(len == expected);

    printf("length pass\n");
}

void test_value_count(struct node* head) {
    /* Check with a valid value */
    int expected = 1;
    int count = value_count(head, head->value);
    assert(count == expected);

    /* Add a duplicate value */
    insert(&head, head->value, 2);
    expected = 2;
    count = value_count(head, head->value);
    assert(count == expected);

    /* Test with bogus value */
    expected = 0;
    count = value_count(head, 124);
    assert(count == expected);

    printf("test_value_count pass\n");
}

int main(void) {
    int head_value = 25;
    int test_value = 88;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->value = head_value;
    head->next = NULL;
    test_insert(&head, test_value);
    test_find_at_index(head);
    test_find_with_value(head);
    test_length(head);
    test_value_count(head);
    test_remove_at_index(&head);
    test_remove_with_value(&head, test_value);
    free_list(head);
}