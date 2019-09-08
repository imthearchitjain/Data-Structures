#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
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
        cout << temp->data << endl;
        temp = temp->next;
        count++;
    }
    cout << "\nNo of nodes in the list :" << count << endl;
}

void remove_end(node **head) // REMEMBER TO PASS THE HEAD AS DOUBLE POINTER
{
    if (*head == nullptr)
        return;

    if ((*head)->next == nullptr)
    {
        *head = nullptr;
        return;
    }

    node *q = *head;
    node *p = new node();
    while (q->next != nullptr)
    {
        p = q;
        q = q->next;
    }

    p->next = nullptr;
    free(q);
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
    remove_end(&head);
    printlist(head);
}
