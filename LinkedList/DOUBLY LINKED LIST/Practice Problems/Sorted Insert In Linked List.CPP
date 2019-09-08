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
        return;
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
void push(node **head, int data)
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
void sorted_insert(node **head, node **tail, int data)
{
    node *newnode = new node();
    newnode->data = data;
    if (*head == nullptr)
    {
        newnode->next = nullptr;
        newnode->prev = nullptr;
        *head = newnode;
        *tail = newnode;
    }
    else if ((*head)->next == nullptr)
    {
        if (newnode->data <= (*head)->data)
        {
            newnode->next = *head;
            (*head)->prev = newnode;
            *head = newnode;
            (*head)->prev = nullptr;
        }
        else
        {
            (*head)->next = newnode;
            newnode->prev = *head;
            *tail = newnode;
            (*tail)->next = nullptr;
        }
        
    }
    else
    {
        node *start = *head;
        while (start != nullptr)
        {
            if(data>start->data)
            {
                start = start->next;
            }
            else
            {
                if (start == *head)
                {
                    newnode->next = *head;
                    (*head)->prev = newnode;
                    *head = newnode;
                    (*head)->prev = nullptr;
                    break;
                }
                else
                {
                    start->prev->next = newnode;
                    newnode->prev = start->prev;
                    newnode->next = start;
                    start->prev = newnode;
                    break;
                }
            }
            
        }
        if(!start)
        {
            newnode->prev = *tail;
            (*tail)->next = newnode;
            newnode->next = nullptr;
            *tail = newnode;
        }
    }
    
}
int main()
{
    int n;
    cout << "\nEnter the no of nodes :";
    cin >> n;
    int data;
    node *head = new node();
    node *tail = new node();
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        sorted_insert(&head, &tail, data);
    }
    printlist(head);
}