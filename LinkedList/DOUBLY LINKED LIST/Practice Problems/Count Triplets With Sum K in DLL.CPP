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
void findpairs(node *head, int n,int &cnt)
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
            cnt++;
            last = last->prev;
            head = head->next;
        }
    }
}
int findtriplets(node *head, int n)
{
    int cnt = 0;
    node *temp = head;
    while (temp->next != nullptr)
    {
        findpairs(temp->next, n - temp->data, cnt);
        temp = temp->next;
        
    }
    return cnt;
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
    
    int sum;
    cout << "\nEnter the sum : ";
    cin >> sum;
    int u = findtriplets(head, sum);
    cout << "\nThe no of triplets are : " << u;
}