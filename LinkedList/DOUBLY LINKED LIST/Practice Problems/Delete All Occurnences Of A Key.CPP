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
void remove_key(node **head, int key)
{
    node *curr = *head;
    node *prev = nullptr;
    node *temp = nullptr;

    while (curr != nullptr)
    {
        if (curr->data == key)
        {
            prev = curr->prev;
            if (curr == *head)
            {
                temp = curr;
                curr = curr->next;
                *head = curr;
                free(temp);
                (*head)->prev = nullptr;
            }
            else if (curr->next == nullptr)
            {
                temp = curr;
                curr = curr->next;
                prev->next = nullptr;
                free(temp);
            }
            else
            {
                temp = curr;
                curr = curr->next;
                prev->next = curr;
                curr->prev = prev;
                free(temp);
            }
        }
        else
        {
            curr = curr->next;
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
    head = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        push(&head, data);
    }
    reverse(&head);
    printlist(head);
    int m;
    cout << "\nThe Key to be removed : ";
    cin >> m;

    remove_key(&head, m);
    printlist(head);
}