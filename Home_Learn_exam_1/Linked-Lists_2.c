#include <stdio.h>
#include <stdlib.h> // for malloc

struct node 
{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

void printlist(node_t *head); // Prints all the nodes.

node_t *create_new_node(int value); // Creates a new node.

node_t *insert_at_head(node_t **head, node_t *node_to_insert); // Adds the node to the next linked list.

node_t *find_node(node_t *head, int value); // Retrieves the node of the value.

node_t *insert_after_node(node_t *node_to_insert_after, node_t *newnode); // Inserts a new node between the 'node_to_insert_after'
// and the next node (new_node).

void remove_node(node_t **head, node_t *node_to_remove); // Deletes the specified node and reconnects the
// remaining nodes accordingly.

int main() 
{
    node_t *head = NULL; // Head of the linked list.
    node_t *tmp;

    for (int i = 0; i < 25; i++) // Creates a total of 25 nodes from 0 to 24.
    {
        tmp = create_new_node(i);   // Creates a new node.
        insert_at_head(&head, tmp); // Adds a new node to the linked list.
    }

    tmp = find_node(head, 13); // Searches the linked list for the value 13.

    printf("Found node with value %d\n", tmp->value);
    printf("Adding new node after %d \n", tmp->value);
    insert_after_node(
    tmp, create_new_node(75)); // Inserts the next node after the 'tmp' node.

    printlist(head); // Prints all the nodes.

    printf("\nDeletes node %d\n", tmp->value);
    remove_node(&head, tmp);  // Deletes the specified node and reconnects the
    // remaining nodes accordingly.
    remove_node(&head, head); // Deletes the specified node and reconnects the
    // remaining nodes accordingly.
    printlist(head);          // Prints all the nodes.
    printf("\n");

    tmp = find_node(head, 15); // Searches the linked list for the value 13.
    printf("\nDeletes node %d\n", tmp->value);

    remove_node(&head, tmp);  // Deletes the specified node and reconnects the
    // remaining nodes accordingly.
    remove_node(&head, head); // Deletes the specified node and reconnects the
    // remaining nodes accordingly.
    printlist(head);          // Prints all the nodes.
    printf("\n");

    //printlist(head); // Prints all the nodes.

    return 0;
}

void printlist(node_t *head) // Prints all the nodes.
{
    node_t *temporary = head;
    while (temporary != NULL) 
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

node_t *create_new_node(int value) 
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) 
{
    node_to_insert->next = *head;
    if (*head != NULL) {
    (*head)->prev = node_to_insert;
    }
    *head = node_to_insert;
    node_to_insert->prev = NULL;
    return node_to_insert;
}

node_t *find_node(node_t *head, int value) 
{
    node_t *tmp = head;
    while (tmp != NULL) {
    if (tmp->value == value) {
    return tmp;
    }
    tmp = tmp->next;
    }
    return NULL;
}

node_t *insert_after_node(node_t *node_to_insert_after, node_t *newnode) 
{
    newnode->next = node_to_insert_after->next;
    if (newnode->next != NULL) {
    newnode->next->prev = node_to_insert_after;
    }
    newnode->prev = node_to_insert_after;
    node_to_insert_after->next = newnode;
}

void remove_node(node_t **head, node_t *node_to_remove) // Deletes the specified node and reconnects the
// remaining nodes accordingly.
{
    if (*head == node_to_remove) 
    {
        *head = node_to_remove->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } 
    else
    {
        node_to_remove->prev->next = node_to_remove->next;
        if (node_to_remove->next != NULL) 
        {
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
}
