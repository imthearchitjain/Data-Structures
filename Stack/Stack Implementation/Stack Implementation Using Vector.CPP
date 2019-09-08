// PROGRAM OF STACK IMPLEMENTATION USING VECTOR
// BASIC OPERATION LIKE PUSHING DATA, POPING DATA, LENGTH OF STACK,

#include <iostream>
#include <vector>
using namespace std;
class stack
{
  public:
    // DATA MEMBERS
    vector<int> a; // DATA STORING
    int top;       // KEEPS TRACK OF TOP ELEMENT INDEX IN STACK
    int bottom;    // BOTTOM MOST ELEMENT OF THE STACK
    int length;    // NO OF ELEMENTS IN THE STACK
    int minimum;   // MINIMUM ELEMENT OF STACK
    int maximum;   // MAXIMUM ELEMENT IN THE STACK

    // THIS IS CONSTRUCTOR
    // IT INITIALIZE DATA MEMBERS OF NEWLY DECLARED STACK
    // NEWLY DECLARED STACK IS EMPTY SO WE LENGTH AS 0 AND TOP INDEX AS -1
    stack()
    {
        length = 0;
        top = -1;
    }
    // MEMBER FUNCTION TO INSERT AN ELEMENT IN STACK
    void push(int data)
    {
        // COMPUTES MAXIMUM AND MINIMUM WHILE ENTERING THE STACK ITSELF
        if (top == -1)
        {
            minimum = data;
            maximum = data;
        }
        if (data > maximum)
            maximum = data;
        if (data < minimum)
            minimum = data;
        // USING VECTOR LIBRARY FUNCTION TO PUSH ELEMENTS IN STACK
        a.push_back(data);
        top++;
        length = a.size();
    }
    //MEMBER FUNCTION THAT TAKES OUT THE TOP ELEMENT FROM THE STACK
    void pop()
    {
        if (top == -1)
            cout << "\nStack is empty...";
        else
        {
            cout << a.back();
            top--;
            a.pop_back();
            length = a.size();
        }
    }
    // MEMBER FUNCTION THAT PRINTS THE COMPLETE STACK
    void print()
    {
        int i = top;
        cout << "\nTop ->";
        while (i >= 0)
        {
            cout << a[i--] << " ";
        }
    }
    // MEMBER FUCNTION THAT  GIVES THE NO OF ELEMENTS IN STACK
    int getlength()
    {
        return length;
    }
    // MEMBER FUNCTION THAT GIVES MIDDLE ELEMENT OF THE STACK
    int middle()
    {
        if (top == -1)
        {
            cout << "\nStack empty ";
            return 0;
        }
        return a[length / 2];
    }
    // MEMBER FUNCTION THAT GIVES THE LAST ELEMENTS IN THE STACK
    int last()
    {
        if (top == -1)
        {
            cout << "\nStack empty ";
            return 0;
        }
        return a.front();
    }
    // MEMBER FUNCTION THAT GIVES THE MINIMUM 
    int get_min()
    {
        if (top == -1)
        {
            cout << "\nStack empty ..";
            return 0;
        }
        return minimum;
    }
    // MEMBER FUNCTION THAT GIVES THE MAXIMUM
    int get_max()
    {
        if (top == -1)
        {
            cout << "\nStack empty ..";
            return 0;
        }
        return maximum;
    }
};

int main()
{
    stack s;
    int n;
    int data;
    cout << "\nEnter no of elements in stack :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Data :";
        cin >> data;
        s.push(data);
    }
    // DOING ALL THE OPERATIONS DEFINED INSIDE THE CLASS
    cout << "\nPrinting the stack :";
    s.print();
    cout << "\nLenght of stack : " << s.getlength();
    cout << "\nMaximum : " << s.get_max();
    cout << "\nMinimum : " << s.get_min();
    cout << "\nMiddle Element in stack : " << s.middle();
    cout << "\nLast element : " << s.last();
    s.pop();
    s.print();
    cout << "\nLenght of stack : " << s.getlength();
    cout << "\nMaximum : " << s.get_max();
    cout << "\nMinimum : " << s.get_min();
    cout << "\nMiddle Element in stack : " << s.middle();
    cout << "\nLast element : " << s.last();
}
