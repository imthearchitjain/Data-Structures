#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void delete_list(node *head)
{
    if (head == nullptr)
        return;
    delete_list(head->next);
    delete head;
}
void printlist(node *head)
{
    
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();
    head->data = 1;      // ENTERING DATA TO NODES
    head->next = second; // LINKING HEAD NODE TO SECOND NODE

    second->data = 2;
    second->next = third; // LINKING SECOND TO THIRD
    third->data = 3;
    third->next = nullptr;
    printlist(head);
    delete_list(head);
    cout << "\nLinked list deleted";
}