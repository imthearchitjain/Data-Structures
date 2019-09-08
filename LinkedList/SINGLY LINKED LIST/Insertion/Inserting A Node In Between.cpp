#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data =0)
    {
        this->data = data;
        next = nullptr;
    }
};
void printlist(node *head)
{
    int count = 0;
    if (head == nullptr)
    {
        cout << "\nList is empty.";
        return;
    }
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL\n";
    cout << "\nNo of nodes in the list :" << count;
}

void insert(node **head, int pos) // REMEMBER TO PASS THE HEAD AS DOUBLE POINTER
{
    int data;
    cout << "\nEnter the data for new node : ";
    cin >> data;
    node *newnode = new node();
    newnode->data = data;
    node *p = new node();
    node *q = new node();
    p = *head;
    int k = 1;
    if (k == pos)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    while (p != nullptr && k < pos)
    {
        k++;
        q = p;
        p = p->next;
    }
    q->next = newnode;
    newnode->next = p;
}
void insertatend(node **head) // REMEMBER TO PASS THE HEAD AS DOUBLE POINTER
{
    int data;
    cout << "\nEnter the data for new node : ";
    cin >> data;
    node *newnode = new node();
    newnode->data = data;
    newnode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newnode;
        return;
    }
    node *p = *head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = newnode;
}
int main()
{
    node *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        insertatend(&head); // HEAD WILL BE PASSED BY ADDRESS IN INSERTING THE NODE TO LINKED LIST

    printlist(head);
    int pos;
    cin >> pos;
    insert(&head, pos);
    printlist(head);
}
