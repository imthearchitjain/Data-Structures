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
void remove_beg(node **head)
{
    node *p =new node();
    p=*head;
    (*head) = (*head)->next;
    (*head)->prev=nullptr;
    delete p;
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
    remove_beg(&head);
    printlist(head);
}