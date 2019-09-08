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
    if (head == nullptr)
        return false;
    if (head->data == key)
        return true;
    else
        return search(head->next, key);
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