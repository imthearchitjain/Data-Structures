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
void segregate_even_odd(node **head) 
{
    node *even = new node();
    node *odd = new node();
    even = nullptr;
    odd = nullptr;
    node *temp = *head;
    while (temp != nullptr)
    {
        if(temp->data%2==0)
            push(&even, temp->data);
        else
            push(&odd, temp->data);
        temp = temp->next;
    }
    reverse(&even);
    reverse(&odd);
    temp = even;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = odd;
    *head = even;
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
    reverse(&head1);
    segregate_even_odd(&head1);
    printlist(head1);
}