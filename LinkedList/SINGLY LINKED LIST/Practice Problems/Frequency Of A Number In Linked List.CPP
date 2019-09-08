#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
int length(node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}
int cnt_key(node *head,int key)
{
    int cnt = 0;
    while (head != nullptr)
    {
        if (head->data == key)
            cnt++;
        head = head->next;
    }
    return cnt;
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

    cout << "\nThe 2 ocurrs in list : " << cnt_key(head,2) << " times";
}