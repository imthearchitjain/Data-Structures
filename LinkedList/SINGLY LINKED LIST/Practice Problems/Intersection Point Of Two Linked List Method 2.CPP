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
int getpoint(int d, node *c, node *e)
{
    node *a = c;
    node *b = e;
    int i;
    for (i = 0; i < d; i++)
    {
        if (a == nullptr)
            return -1;
        a = a->next;
   }
   while (a != nullptr && b != nullptr)
   {
       if (a == b)
       {
           return a->data;
       }
       a = a->next;
       b = b->next;
   }
   return -1;
}
int intersectionpoint(node *a, node *b)
{
    int l1 = length(a);
    int l2 = length(b);
    int d;
    if (l1 > l2)
    {
        d = l1 - l2;
        return getpoint(d, a, b);
    }
    else
    {
        d = l2 - l1;
        return getpoint(d, b, a);
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
        push(&head1, data);
    }
    reverse(&head1);
    node *head2 = new node();
    head2 = nullptr;
    push(&head2, 10);
    reverse(&head2);
    head2->next = head1->next->next->next;

    printlist(head1);
    printlist(head2);

    cout << "\nIntersection point is : " << intersectionpoint(head1, head2);

}#include <iostream>
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
int getpoint(int d, node *c, node *e)
{
    node *a = c;
    node *b = e;
    int i;
    for (i = 0; i < d; i++)
    {
        if (a == nullptr)
            return -1;
        a = a->next;
   }
   while (a != nullptr && b != nullptr)
   {
       if (a == b)
       {
           return a->data;
       }
       a = a->next;
       b = b->next;
   }
   return -1;
}
int intersectionpoint(node *a, node *b)
{
    int l1 = length(a);
    int l2 = length(b);
    int d;
    if (l1 > l2)
    {
        d = l1 - l2;
        return getpoint(d, a, b);
    }
    else
    {
        d = l2 - l1;
        return getpoint(d, b, a);
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
        push(&head1, data);
    }
    reverse(&head1);
    node *head2 = new node();
    head2 = nullptr;
    push(&head2, 10);
    reverse(&head2);
    head2->next = head1->next->next->next;

    printlist(head1);
    printlist(head2);

    cout << "\nIntersection point is : " << intersectionpoint(head1, head2);

}