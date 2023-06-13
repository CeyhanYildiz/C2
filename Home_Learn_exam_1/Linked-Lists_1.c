#include <stdio.h>
#include <stdlib.h> // for malloc

struct node {
    int data;
    // int data_2;
    // int data_3;
    // .
    // .
    // .
    struct node *link;
};


int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    
    head->data = 45;
    head->link = NULL;

    printf("%d", head->data);
    return 0;
}