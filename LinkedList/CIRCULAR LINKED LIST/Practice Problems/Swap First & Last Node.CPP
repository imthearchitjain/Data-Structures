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
    } while (temp != head && temp != nullptr);
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
    } while (temp != head && temp != nullptr);
    if (temp == head)
        cout << "head";
    else
        cout << "NULL";


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
void exchange_last_first(node **head)
{
    node *temp = *head;
    node *prev = nullptr;
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    temp->next = (*head)->next;
    (*head)->next = temp;
    *head = temp;
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes :";
    cin >> n;
    int data;
    node *head1 = new node();
    head1 = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        put(&head1, data);
    }
    printlist(head1);
    exchange_last_first(&head1);
    printlist(head1);
}