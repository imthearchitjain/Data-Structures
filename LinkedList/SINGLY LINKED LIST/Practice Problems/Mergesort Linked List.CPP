#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
};
void printlist(node *head);
node* merge(node *a, node *b)
{
    node *head = nullptr;
    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;

    if (a->data < b->data)
    {
        head = a;
        head->next = merge(a->next, b);
    }
    else
    {
        head = b;
        head->next = merge(a, b->next);
    }
    
    return head;
}
void fbsplit(node *head, node **a, node **b)
{
    node *fast;
    node *slow;
    slow = head;
    fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = nullptr;
}
void mergesort(node **head)
{
    if ((*head)->next != nullptr && *head != nullptr)
    {
        node *head1 = *head;
        node *a = new node();
        node *b = new node();
        fbsplit(head1, &a, &b);
        mergesort(&a);
        mergesort(&b);
        printlist(a);
        printlist(b);
        *head = merge(a, b);
    }
}
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

int main()
{
    int n;
    cout << "\nEnter the no of nodes in list 1 :";
    cin >> n;
    int data;
    node *head1 = new node();
    head1 = nullptr;
    cout << "\nEnter list 1:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data :";
        cin >> data;
        push(&head1, data);
    }
    
    reverse(&head1);
    printlist(head1);
    mergesort(&head1);
    printlist(head1);
}