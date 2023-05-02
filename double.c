#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int value;
    struct node *next;
    struct node *previous;

} node_t;

node_t *make_node(int value, struct node *next, struct node *previous);

void add_back(node_t **list, int value);

void print_list(node_t *list, int backwards);

void remove_node(node_t **list, int value);

int main(int argc, char **argv)
{

    struct node *list = NULL; // initially the tree is NULL

    add_back(&list, 42);
    add_back(&list, 13);
    add_back(&list, 50);
    add_back(&list, 15);
    add_back(&list, 2);

    print_list(list, 0); // 42, 13, 50, 15, 2
    print_list(list, 1);

    remove_node(&list, 15);
    remove_node(&list, 13);
    remove_node(&list, 42);
    print_list(list, 0); // 50, 2
}

node_t *make_node(int value, node_t *next, node_t *previous)
{
    printf("making a node\n");
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = next;
    node->previous = previous;

    if (node->next != NULL)
    {
        printf("NEXT: %d\n", node->next->value);
    }
    else if (node->previous != NULL)
    {
        printf("PREV: %d\n", node->previous->value);
    }
    return node;
}

void add_back(node_t **list, int value)
{
    node_t *curr = *list;
    if (*list == NULL)
    {
        printf("add_back: %d\n", value);
        *list = make_node(value, NULL, NULL);
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = make_node(value, NULL, curr);
    }
}

void print_list(node_t *list, int backwards)
{
    if (list == NULL)
    {
        // do nothing
    }
    else if (backwards == 0)
    {
        node_t *node = list;

        while (node != NULL)
        {
            printf("%d ", node->value);
            node = node->next;
        }
        printf("\n");
    }
    else if (backwards == 1)
    {
        node_t *node = list;

        while (node->next != NULL)
        {
            node = node->next;
        }

        while (node != NULL)
        {
            printf("%d ", node->value);
            node = node->previous;
        }
        printf("\n");
    }
}

void remove_node(node_t **list, int value)
{
    printf("removing %d\n", value);
    node_t *curr = *list;

    if (curr != NULL)
    {
        // not the end not the value
        while (curr->next != NULL && curr->value != value) {
            curr = curr->next;
        }
        printf("doubly linked\n");
        node_t *prev = curr->previous;
        node_t *next = curr->next;
        
        prev->next = next;
        next->previous = prev;

        free(curr);
        print_list(*list, 0);

    } else {
        // do nothing
    }
}
