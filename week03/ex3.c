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


void insert_node(struct Node** list, struct Node* node, int pos) {
    if (pos == 0) {
        node->next = *list;
        *list = node;
    } else {
        struct Node* tmp = *list;
        for (int i = 1; i < pos; ++i) {
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
    }
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
    struct Node* head = create_node(0);
    struct Node* new_node1 = create_node(1);
    struct Node* new_node2 = create_node(2);
    struct Node* new_node3 = create_node(3);


//    insert_node(&head, new_node1, 0);
//    insert_node(&head, new_node2, 1);
//    insert_node(&head, new_node3, 2);
//    delete_node(&head, head);
//    delete_node(&head, new_node2);
//    delete_node(&head, new_node3);
    print_list(head);
    return 0;
}
