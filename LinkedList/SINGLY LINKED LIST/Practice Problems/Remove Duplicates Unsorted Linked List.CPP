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
void deletekey(node *mhead,node **head, int key)
{
    node *curr = *head;
    node *prev = mhead;
    node *temp = nullptr;
    while (curr != nullptr)
    {
        temp = curr;
        
        if (curr->data == key)
        {
            curr = curr->next;
            prev->next = curr;
            free(temp);
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
        

    }
}
void remove_duplicates(node **head)
{
    node *curr = *head;
    if (curr == nullptr)
        return;

    while (curr->next != nullptr)
    {
        deletekey(curr, &(curr->next), curr->data);
        curr = curr->next;
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