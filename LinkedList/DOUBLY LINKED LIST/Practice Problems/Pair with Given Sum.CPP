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
node *merge(node *a, node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    node *head = new node();
    head->prev = nullptr;
    node *temp = head;
    while (a != nullptr && b != nullptr)
    {
        if (a->data < b->data)
        {
            a->prev = temp;
            temp->next = a;   
            a = a->next;
        }
        else
        {
            b->prev = temp;
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if (a == nullptr)
    {
        b->prev = temp;
        temp->next = b;
    }
    if (b == nullptr)
    {
        a->prev = temp;
        temp->next = a; 

    }
    head = head->next;
    return head;
}
void split(node *head, node **a, node **b)
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
void findpairs(node *head, int n)
{
    node *last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    while (last != head && last->next != head)
    {
        int sum = last->data + head->data;
        if (sum > n)
        {
            last = last->prev;
        }
        else if (sum < n)
        {
            head = head->next;
        }
        else
        {
            cout << "{ " << head->data << " , " << last->data << " "
                 << "} ";
            last = last->prev;
            head = head->next;
        }
        
    }
}
node* mergesort(node *head)
{
    if (head == nullptr || (head)->next == nullptr)
        return head;
    
    node *a = nullptr;
    node *b = nullptr;
    split(head, &a, &b);
    
    a = mergesort(a);
    b = mergesort(b);
    head = merge(a, b);
    return head;
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
    head = mergesort(head);
    printlist(head);
    int sum;
    cout << "\nEnter the sum : ";
    cin >> sum;
    findpairs(head, sum);
}