#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    bool Ltag, Rtag;
    Node *left;
    Node *right;

    Node(int data = 0)
    {
        left = right = nullptr;
        this->data = data;
    }
};
// void insert(Node **root, int data)
// {
//     if (!*root)
//         *root = new Node(data);
//     else if (data < (*root)->data)
//         insert(&(*root)->left, data);
//     else
//         insert(&(*root)->right, data);
// }
void preOrder(Node *root)
{
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
class List
{
public:    
    int data;
    List *next;
    List(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
};
void push(List **head, int data)
{
    List *newnode = new List(data);
    newnode->next = *head;
    *head = newnode;
}
int countNodes(List *head)
{
    int count = 0;
    List *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void printList(List *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
Node *sortedListToBSTRecur(List **head_ref, int n)
{
    if (n <= 0)
        return nullptr;
    Node *left = sortedListToBSTRecur(head_ref, n / 2);
    Node *root = new Node((*head_ref)->data);
    root->left = left;
    *head_ref = (*head_ref)->next;
    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

    return root;
}
Node *sortedListToBST(List *head)
{
    /*Count the number of nodes in Linked List */
    int n = countNodes(head);

    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}

int main()
{
    List *head = nullptr;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given Linked List ";
    printList(head);

    /* Convert List to BST */
    Node *root = sortedListToBST(head);
    cout << "\nPreOrder Traversal of constructed BST ";
    preOrder(root);

    return 0;
}