/**
 * Functions related to linked list data structure
 */

typedef struct node {
    int value;
    node *next;
} Node;

typedef Node* ptr_node;

ptr_node create_empty_list(void) {
    return NULL;
}

void delete_list(ptr_node list) {
    if (list != NULL) {
        if (list->next != NULL) {
            delete_list(list->next);
        }

        free(list);
    }
}

void add_item(ptr_node list, Node item) {
    ptr_node aux;

    if (list == NULL) {
        list = item;
    } else {
        for (aux = list; aux->next != NULL; aux = aux->next);
        aux->next = item;
    }
}

void remove_item(ptr_node list, int value) {
    ptr_node aux = NULL
    ptr_node tmp = NULL;

    if (list != NULL) {
        for (aux; aux->next != NULL; aux = aux->next) {
            if (aux->next->value == value) {
                aux->next = aux->next->next;
            }
        }
    }
}