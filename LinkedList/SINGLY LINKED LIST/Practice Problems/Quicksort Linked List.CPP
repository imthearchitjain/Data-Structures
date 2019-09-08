#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *createNode(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insert(Node **head, int x)
{
    Node *newnode = createNode(x);
    if(*head == NULL)
        *head = newnode;
    else
    {
        newnode->next = *head;
        *head = newnode;
    }
    
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
Node *partition(Node *head, Node *end, Node **newhead, Node **newend)
{
    Node *pivot = end;
    Node *prev = NULL, *tail = pivot, *curr = head;
    while (curr != pivot)
    {
        if(curr->data < pivot->data)
        {
            if(*newhead == NULL)
                *newhead = curr;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if(prev)
                prev->next = curr->next;
            Node *temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
        
    }
    if((*newhead) == NULL)
        *newhead = pivot;
    *newend = tail;
    return pivot;
}
Node *getTail(Node *head)
{
    while (head && head->next)
        head = head->next;

    return head;
}
void push(struct Node **head_ref, int new_data)
{
    Node *new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
Node *recQuickSort(Node *head, Node *end)
{
    if(!head || head == end)
        return head;
    Node *newhead = NULL, *newend = NULL;
    Node *pivot = partition(head, end, &newhead, &newend);
    if(newhead != pivot)
    {
        Node *temp = newhead;
        while(temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        newhead = recQuickSort(newhead, temp);
        temp = getTail(newhead);
        temp->next = pivot;
    }

    pivot->next = recQuickSort(pivot->next, newend);
    return newhead;
}

void quicksort(Node **head)
{
    *head = recQuickSort(*head, getTail(*head));
    return;
}
int main()
{
    struct Node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout << "Linked List before sorting \n";
    printlist(a);

    quicksort(&a);

    cout << "Linked List after sorting \n";
    printlist(a);

    return 0;
}