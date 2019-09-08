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
void sorted_insert(node **head, node *newnode)
{
    node *temp = *head;
    node *prev = *head;
    if (*head == nullptr)
        return;
    if (newnode->data <= (*head)->data)
    {
        do
        {
            temp = temp->next;
        } while (temp->next != *head);
        temp->next = newnode;
        newnode->next = *head;
        *head = newnode;
        return;
    }
    do
    {
        prev = temp;
        temp = temp->next;
        if (newnode->data >= prev->data && newnode->data <= temp->data)
        {
            prev->next = newnode;
            newnode->next = temp;
            return;
        }

    } while (temp->next != *head);
    if (temp->next == *head)
    {
        temp->next = newnode;
        newnode->next = *head;
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
    node *newnode = new node();
    cout << "\nEnter data :";
    cin >> newnode->data;
    newnode->next = nullptr;
    printlist(head1);
    sorted_insert(&head1, newnode);
    printlist(head1);
}