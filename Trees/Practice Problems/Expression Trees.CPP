#include<bits/stdc++.h>
using namespace std;
class Btree{
public:
    char data;
    Btree *left;
    Btree *right;
    Btree(char data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
bool isOperand(char c)
{
    return (c <= 90 && c >= 65) || (c >= 97 && c <= 122);
}
/*int evaluateTree(Btree *root)
{
    if(root)
    {
        if(isOperand(root))
            return root->data - 48;
        int a = evaluateTree(root->left);
        int b = evaluateTree(root->right);
        return calculate(a, b, root->data);
    }
}
*/
Btree *constructBtree(char *s)
{
    stack<Btree *> st;
    Btree *t1, *t2, *t3;
    for (int i = 0; s[i] !='\0'; i++)
    {
        if(isOperand(s[i]))
        {
            t1 = new Btree(s[i]);
            st.push(t1);
        }
        else
        {
            t1 = new Btree(s[i]);
            t2 = st.top();
            st.pop();
            t3 = st.top();
            st.pop();
            t1->left = t3;
            t1->right = t2;
            st.push(t1);
        }
    }
    return st.top();
}
void inorder(Btree *root)
{
    
    if(!root)
        return;
    cout << "(";
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    cout << ")";
}
int main()

{
    char postfix[] = "ab+ef*g*-";
    Btree *tree = constructBtree(postfix);
    inorder(tree);
}