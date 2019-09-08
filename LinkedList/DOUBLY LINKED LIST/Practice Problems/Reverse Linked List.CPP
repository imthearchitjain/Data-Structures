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

void reverse(node **head)
{
    node *current = *head;
    node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if(temp!=nullptr)
    {
        *head = temp->prev;
    }
}
int main()
{
    node *head = new node(); //FOR SIMPLICITY TAKING ONLY THREE NODES
    node *second = new node();
    node *third = new node();
    node *fourth = new node();

    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE
    head->prev = nullptr;
    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    second->prev = head;
    third->data = 3;
    third->next = fourth;
    third->prev = second;
    fourth->prev = third;
    fourth->data = 4;
    fourth->next = nullptr; // SET LAST NODE POINTER TO NULL
    printlist(head);
    reverse(&head);
    printlist(head);
}