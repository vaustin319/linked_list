#include "../linked_list.h"
#include <assert.h>
#include <stdlib.h>


void test_insert(struct node** head) {
    /* Check that an element can be inserted */
    int value = -32;
    int index = 1;
    insert(head, value, index);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->next->value == value);

    /* Check that an element can be inserted at the beginning */
    int new_value = 64;
    index = 0;
    insert(head, new_value, index);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->value == new_value);

    /* Check that an invalid index does not corrupt the list */
    int invalid_index = 48;
    insert(head, new_value, invalid_index);
    assert(*head != NULL);
    print_list(*head);
    assert((*head)->next != NULL);
    assert((*head)->value == new_value);

    printf("test_insert pass\n");
}

void test_remove_at_index(struct node** head) {
    /* Test we can remove the head of the list */
    int index = 0;
    int expected = (*head)->next->value;
    remove_at_index(head, index);
    assert((*head)->value == expected);
    print_list(*head);

    /* Test we can remove any element from the list */
    index = 1;
    expected = (*head)->next->next->value;
    remove_at_index(head, index);
    assert((*head)->next->value == expected);
    print_list(*head);

    printf("test_remove_at_index pass\n");
}

void test_remove_with_value(struct node** head) {
    /* Remove last value */
    int value = 25;
    remove_with_value(head, value);
    print_list(*head);
    
    /* Remove first value */
    remove_with_value(head, (*head)->value);
    print_list(*head);
    
    /* Add dup value, and then try to remove it.*/
    int index = 4;
    int expected = (*head)->next->next->value;
    insert(head, (*head)->next->value, index);
    print_list(*head);
    remove_with_value(head, (*head)->next->value);
    print_list(*head);
    assert((*head)->next->value == expected);

    printf("test_remove_with_value pass\n");
}

void test_find_at_index(struct node* head) {
    /* Check if we get the right value for the given index */
    int index = 1;
    struct node* result = find_at_index(head, index);
    assert(result != NULL);
    assert(result->value == head->next->value);

    /* Check that an out of bounds index returns NULL */
    index = 40;
    result = find_at_index(head, index);
    assert(result == NULL);

    printf("test_find_at_index pass\n");
}

void test_find_with_value(struct node* head) {
    /* Check that we get the correct returned value */
    int expected = 25;
    struct node* result = find_with_value(head, expected);
    assert(result != NULL);
    assert(result->value == expected);

    /* Check that a value not in the list returns NULL */
    result = find_with_value(head, 400);
    assert(result == NULL);

    printf("test_find_with_value pass\n");
}

void test_length(struct node* head) {
    size_t expected = 8;
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

void test_find_smallest(struct node* head) {
    struct node* smallest = find_smallest(head);
    int expected = 0;
    assert(smallest != NULL);
    assert(smallest->value == expected);

    printf("test_find_smallest pass\n");
}

void test_find_largest(struct node* head) {
    struct node* largest = find_largest(head);
    int expected = 174;
    assert(largest != NULL);
    assert(largest->value == expected);

    printf("test_find_largest pass\n");
}

void test_find_next_smallest(struct node* head) {
    /* Check we can fidn the next smallest*/
    int value = 2;
    struct node* next_smallest = find_next_smallest(head, value);
    int expected = 0;
    assert(next_smallest != NULL);
    assert(next_smallest->value == expected);

    /* Check we return null when value is the smallest */
    int smallest = 0;
    next_smallest = find_next_smallest(head, smallest);
    assert(next_smallest == NULL);

    /* Check still works when given value is not in the list */
    value = 9;
    next_smallest = find_next_smallest(head, value);
    expected = 8;
    assert(next_smallest != NULL);
    assert(next_smallest->value == expected);

    printf("test_find_next_smallest pass\n");
}

void test_find_next_largest(struct node* head) {
    /* Check we can fidn the next largest*/
    int value = 2;
    struct node* next_largest = find_next_largest(head, value);
    int expected = 8;
    assert(next_largest != NULL);
    assert(next_largest->value == expected);

    /* Check we return null when value is the largest */
    int largest = 174;
    next_largest = find_next_largest(head, largest);
    assert(next_largest == NULL);

    /* Check still works when given value is not in the list */
    value = 9;
    next_largest = find_next_largest(head, value);
    expected = 174;
    assert(next_largest != NULL);
    assert(next_largest->value == expected);

    printf("test_find_next_largest pass\n");
}


void build_list(struct node** head) {
    int list_size = 7;
    const int values[] = {28, 13, 2, -5, 8, 174, 0};
    for (int i = 0; i < list_size; i++) {
        insert(head, values[i], i);
    }

    printf("Original list values:\n");
    print_list(*head);
}

void run_tests(struct node** head) {
    test_insert(head);
    test_remove_at_index(head);
    test_find_with_value(*head);
    test_find_at_index(*head);
    test_length(*head);
    test_value_count(*head);
    test_remove_at_index(head);
    test_remove_with_value(head);
    test_find_smallest(*head);
    test_find_largest(*head);
    test_find_next_smallest(*head);
    test_find_largest(*head);
}

int main(void) {
    int head_value = 25;
    int test_value = 88;
    struct node* head = (struct node*) malloc(sizeof(struct node));
    head->value = head_value;
    head->next = NULL;
    build_list(&head);
    run_tests(&head);
    free_list(head);
}