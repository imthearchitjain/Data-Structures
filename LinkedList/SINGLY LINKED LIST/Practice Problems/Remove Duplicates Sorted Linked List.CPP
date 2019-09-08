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
        cout << head->data << " ";
        head = head->next;
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
void remove_duplicates(node **head)
{
    if (*head == nullptr)
        return;
    node *prev = *head;
    node *next = (*head)->next;
    node *temp = new node();
    while (next != nullptr)
    {
        temp = next;
        next = next->next;
        if (prev->data == temp->data)
        {
            prev->next = next;
            free(temp);
        }
        else
        {
            prev = prev->next;
        }
    }
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes you want to enter :";
    cin >> n;
    int data;
    node *head = new node();
    head = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        push(&head, data);
    }
    reverse(&head);
    printlist(head);
    remove_duplicates(&head);
    printlist(head);
}