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
node* remove_duplicates(node *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    if(head->data==head->next->data)
    {
        node *temp = head->next;
        head->next = head->next->next;
        free(temp);
        return remove_duplicates(head);
    }
    else
    {
        head->next = remove_duplicates(head->next);
        return head;
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
    head = remove_duplicates(head);
    printlist(head);
}