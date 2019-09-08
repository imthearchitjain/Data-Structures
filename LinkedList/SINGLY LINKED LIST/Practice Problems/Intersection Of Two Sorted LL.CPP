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
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}
void printlist(node *head)
{

    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
        if (head == nullptr)
            cout << "NULL";
    }

    cout << endl;
}
void push(node **head, int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void reverse(node **head)
{
    node *prev = nullptr;
    node *curr = *head;
    node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
node *intersection(node *a, node *b)
{
    node dummy;
    node *tail = &dummy;
    dummy.next = nullptr;
    while (a != nullptr && b != nullptr)
    {
        if (a->data == b->data)
        {
            push(&(tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return dummy.next;
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
        push(&head1, data);
    }
    node *head2 = new node();
    head2 = nullptr;
    int m;
    cout<<"\nEnter the no of nodes in the list :";
    cin >> m;

    cout << "\nEnter list :\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        push(&head2, data);
    }
    reverse(&head1);
    reverse(&head2);
    printlist(head1);
    printlist(head2);
    node *head=intersection(head1,head2);
    printlist(head);
}