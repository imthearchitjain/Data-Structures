#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class mergableStack
{

public:
    node *top;
    node *bottom;


    mergableStack()
    {
        top = nullptr;
    }
    void push(int data)
    {
        
        node *newnode = new node();
        newnode->data = data;
        newnode->next = top;
        if (top == nullptr)
            bottom = newnode;    
        top = newnode;
    }
    int pop()
    {
        node *temp = top;
        int data = temp->data;
        top = top->next;
        free(temp);
        return data;
    }
    void merge(mergableStack s)
    {
        bottom->next = s.top;
        bottom = s.bottom;
    }
};

int main()
{
    mergableStack s1, s2;
    int m, n, data;
    cout << "\nEnter the no of elements in stack 1 : ";
    cin >> m;
    cout << "\nEnter the no of elements in stack 2 : ";
    cin >> n;
    cout << "\nStack 1 : \n";
    while(m--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s1.push(data);
    }
    cout << "\nStack 2 : \n";
    while (n--)
    {
        cout << "\nEnter the data : ";
        cin >> data;
        s2.push(data);
    }

    s1.merge(s2);
    cout << "\nbottom element of s1 : " << s1.bottom->data;
}

