#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
bool search(node *head, int key)
{
    node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    if (curr = nullptr)
        return false;
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
    if (search(head, 2))
        cout << "\nNode found..";
    else
        cout << "\nNode not found..";
}