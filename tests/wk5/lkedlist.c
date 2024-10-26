#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node* create(int i);
node *insert(node *head, int i);
void delete(node *head, int i);
void destroy(node *head);
void printlst(node *head);

int main(void)
{
    // create an array of int.
    int array[9];
    for (int i = 0; i < 9; i++)
    {
        array[i] = i * i;
    }
    //create a linked list first
    node *list = create(0);

    // insert numbers into the linked list

    for (int i = 0; i < 9; i++)
    {
        list = insert(list, array[i]);
    }
    printlst(list);
    destroy(list);

}

node* create(int i)
{
    // to do
    node * tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->number = i;
    tmp->next = NULL;
    return tmp;
}
node *insert(node *head, int i)
{
    // insert the node at the beginning of the list
    node *tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->number = i;
    tmp->next = head;
    return tmp;

}

void delete(node *head, int i)
{
    // if it's the first element
    node *list = head;
    if (list->number == i)
    {
        head = list->next;
        free(list);
        return;
    }
    else
    {
        node *prev = list;
        list = list->next;
        while (list != NULL)
        {
            if (list->number == i)//to do
            {
                prev->next = list->next;
                free(list);
                list = prev->next;
                return;
            }
            else
            prev = list;
            list = list->next;
        }
    }

}

void destroy(node *head)
{
    // to do
    node *list = head;
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

void printlst(node *head)
{
    node *list = head;
    if (head == NULL)
    {
        printf("it is a NULL list\n");
        return;
    }
    else
    {
        while (list != NULL)
        {
            printf("%i\n", list->number);
            list = list->next;
        }
    }
}