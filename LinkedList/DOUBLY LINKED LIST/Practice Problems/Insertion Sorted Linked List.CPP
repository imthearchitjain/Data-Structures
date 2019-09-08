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
void reverse(node **head)
{
    if (*head == nullptr && (*head)->next == nullptr)
        return ;
    node *curr = *head;
    node *prev = nullptr;
    node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void push(node **head,int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->prev = nullptr;
    if (*head == nullptr)
    {
        newnode->next = nullptr;
        *head = newnode;
        return;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
        return;
    }
    
}
void printlist(node *head)
{
    cout << "\n";
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
void insert(node **head, int value)
{
    node *newnode = new node();
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = nullptr;
    node *temp = *head;
    if (newnode->data <= temp->data)
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
        return;
    }

    while(temp->next!=nullptr)
    {
        if (newnode->data <= temp->data && newnode->data >= temp->prev->data)
        {
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
            return;
        }
        temp = temp->next;
   }
   if (newnode->data >= temp->data)
   {
       temp->next = newnode;
       newnode->prev = temp;
   }
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes :";
    cin >> n;
    int data;
    node *head = new node();
    head = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        push(&head, data);
    }
    reverse(&head);
    printlist(head);
    int value;
    cout << "\nEnter the value to be inserted : ";
    cin >> value;
    insert(&head, value);
    printlist(head);
}