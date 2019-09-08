#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->data = x;
    return newnode;
}

void push(Node **head, int x)
{
    Node *newnode = createNode(x);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while(temp->next)
        temp = temp->next;
    temp->next = newnode;
}

void deleteWithoutHead(Node **node)
{
    Node *prev;
    if(!*node)
        return;
    Node *temp = *node;
    if(!temp->next)
    {
        *node = NULL;
        return;
    }
    while(temp->next)
    {
        temp->data = temp->next->data;
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
}

void printlist(Node *head)
{
    while(head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
int main()
{
    int n, data;
    Node *head = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        push(&head, data);
    }
    printlist(head);
    deleteWithoutHead(&head);
    printlist(head);
}