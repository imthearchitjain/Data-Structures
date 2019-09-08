#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
    node *prev;
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
void insert(node **head, int pos)
{
    int data;
    cout << "\nEnter the data :";
    cin >> data;
    node *newnode = new node();
    newnode->data = data;
    node *p = new node(), *q = new node();
    p = *head;
    int k=1;
    while (p != nullptr && k<pos)
    {
        k++;
        q = p;
        p = p->next;
    }
    newnode->prev=q;
    newnode->next=p;
    q->next=newnode;
    p->prev=newnode;
}

int main()
{
    node *head = new node(); //FOR SIMPLICITY TAKING ONLY THREE NODES
    node *second = new node();
    node *third = new node();

    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE
    head->prev = nullptr;
    second->prev = head;
    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    third->prev = second;
    third->data = 3;
    third->next = nullptr; // SET LAST NODE POINTER TO NULL
    printlist(head);
    insert(&head,2);
    printlist(head);
}