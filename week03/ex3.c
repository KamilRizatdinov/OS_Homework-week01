#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int value;
};

struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void print_list(struct Node* list) {
    while(list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}


void insert_node(struct Node* list, struct Node* node) {
    while(list->next != NULL) {
        list = list->next;
    }
    list->next = node;
}


void delete_node(struct Node** list, struct Node* node) {
    if (*list == node) {
        *list = node->next;
    } else {
        while ((*list)->next != node) {
            *list = (*list)->next;
        }
        (*list)->next = (*list)->next->next;
    }
}


int main() {
    struct Node* list = create_node(0);
    struct Node* new_node = create_node(1);
    struct Node* new_node2 = create_node(2);
    struct Node* new_node3 = create_node(3);


    insert_node(list, new_node);
    insert_node(list, new_node2);
    insert_node(list, new_node3);
    delete_node(&list, list);
    delete_node(&list, new_node);
    delete_node(list, new_node2);
    delete_node(&list, new_node3);
    print_list(list);
    return 0;
}
