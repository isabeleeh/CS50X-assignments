#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
    node *root = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 0;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    root = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 0;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    root->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(root);
        return 0;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    root->right = n;

    print_tree(root);
    free_tree(root);
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}