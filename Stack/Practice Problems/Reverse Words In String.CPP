#include <iostream>
#include <string>
#include <stack>
using namespace std;
void reverseWords(string &str)
{
    stack<char> s;
    string temp;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
        {
            s.push(str[i]);
        }
        else
        {
            while(!s.empty())
            {
                temp.push_back(s.top());
                s.pop();
            }
            temp.push_back(str[i]);
        }
        
    }
    while(!s.empty())
            {
                temp.push_back(s.top());
                s.pop();
            }
    str = temp;
}
int main()
{
    string str;
    getline(cin, str);
    reverseWords(str);
    cout<<str;
}