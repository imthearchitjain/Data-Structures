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
void check_list(node *head)
{
    node *temp = head;
    if(temp == nullptr)
    {
        cout << "\nList is empty.\n";
        return;
    }
    do
    {
        temp = temp->next;
    }while (temp != nullptr && temp != head);

    if (temp == nullptr)
        cout << "\nLinked list is linear ...\n";
    else if (temp == head)
        cout << "\nLinked list is circular ...\n";
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
    node *head = new node();
    node *second = new node();
    node *third = new node();
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = nullptr;
    printlist(head);
    printlist(head1);
    check_list(head);
    check_list(head1);
}