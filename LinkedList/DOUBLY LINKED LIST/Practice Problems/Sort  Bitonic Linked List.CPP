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
void sort_biotonic(node **head)
{
    node *start = *head;
    node *start_prev = nullptr, *end_prev;
    node *end = *head;
    while (end->next != nullptr)
    {
        end = end->next;
    }
    end_prev = end->prev;

    while (start->next != nullptr)
    {
        if (start->data <= end->data)
        {
            start_prev = start;
            start = start->next;
        }
        else
        {
            if (start == *head)
            {
                end->next = *head;
                (*head)->prev = end;
                *head = end;
                (*head)->prev = nullptr;
                end_prev->next = nullptr;
                end = end_prev;
                end_prev = end_prev->prev;
                start_prev = start->prev;
            }
            else
            {
                start_prev=start->prev;
                start_prev->next = end;
                end->prev = start_prev;
                end->next = start;
                start->prev = end;
                start_prev = start->prev;
                end_prev->next = nullptr;
                end = end_prev;
                end_prev = end_prev->prev;
            }
        }
        printlist(*head);
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
    sort_biotonic(&head);
    printlist(head);
}