#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
};

int length(node *head)
{
    int length = 0;
    node *temp = head;
    if (temp == nullptr)
    {
        return 0;
    }
    do
    {
        length++;
        temp = temp->next;
    } while (temp != head);
    return length;
}
void printlist(node *head)
{
    node *temp = head;
    if (head == nullptr)
    {
        return;
    }
    cout << "head -> ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "head";

    cout << endl;
}
void put(node **head, int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->next = *head;
    if (*head == nullptr)
    {
        newnode->next = newnode;
        *head = newnode;
    }
    node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
}

void reverse(node **head)
{
    node *prev = nullptr;
    node *curr = *head;
    node *next = nullptr;
    while (curr->next != *head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    (*head)->next = curr;
    *head = curr;
}
void split(node *head,node **a,node **b)
{
    if (head == nullptr)
        return;
    node *prev_sptr = head;
    node *prev_fptr = head;
    node *sptr = head;
    node *fptr = head;
    do
    {
        prev_sptr = sptr;
        prev_fptr = fptr;
        sptr = sptr->next;
        fptr = fptr->next->next;
    } while (fptr != head && fptr->next != head);
    if (length(head) % 2 == 0)
    {
        prev_fptr->next->next = sptr;
        prev_sptr->next = fptr;
        *a = fptr;
        *b = sptr;
    }
    else
    {
        fptr->next = sptr->next;
        *b = fptr->next;
        sptr->next = head;
        *a = head;
    }
    
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes in list :";
    cin >> n;
    int data;
    node *head1 = new node();
    head1 = nullptr;
    cout << "\nEnter list :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        put(&head1, data);
    }
    printlist(head1);
    node *a = new node();
    node *b = new node();
    split(head1, &a, &b);
    printlist(a);
    printlist(b);
}