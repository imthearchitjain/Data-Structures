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
node *find(node *head, int a)
{
    while (head != nullptr)
    {
        if (head->data == a)
        {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}
node *find_prev(node *head, int a)
{
    while (head->next != nullptr)
    {
        if (head->next->data == a)
        {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}
void swap_nodes(node **head, int a, int b)
{
    node *aptr = find(*head,a);
    node *aprev = find_prev(*head, a);
    node *bptr = find(*head,b);
    node *bprev = find_prev(*head, b);

    if (aprev != nullptr)
        aprev->next = bptr;
    else
        *head = bptr;
    if (bprev != nullptr)
        bprev->next = aptr;
    else
        *head = aptr;

    node *temp = bptr->next;
    bptr->next = aptr->next;
    aptr->next = temp;
}

int node_data(node *head, int k)
{
    while(k>1)
    {
        head = head->next;
        k--;
    }
    return head->data;
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
    printlist(head1);
    int k;
    cout << "\nEnter the value of k :";
    cin >> k;
    swap_nodes(&head1, node_data(head1, k), node_data(head1, n - k + 1));
    printlist(head1);
}