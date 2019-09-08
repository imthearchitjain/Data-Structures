#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
    node *prev;
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
    if (*head == nullptr)
    {
        newnode->next = nullptr;
        newnode->prev = nullptr;
        *head = newnode;
        return;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        newnode->prev = nullptr;
        *head = newnode;
    }
    

}

void reverse(node **head)
{
    node *prev = nullptr;
    node *curr = *head;
    node *next = nullptr;
    while (curr->next != nullptr)
    {
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    curr->prev = next;
    (*head)= curr;
    
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
    reverse(&head1);
    printlist(head1);
    reverse(&head1);
    printlist(head1);

}