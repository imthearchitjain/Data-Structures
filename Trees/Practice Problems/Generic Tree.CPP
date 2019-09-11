#include <bits/stdc++.h>

using namespace std;
class GenericTree{

    public:
        int data;
        vector<GenericTree *> child;

        GenericTree(int data = 0){
            this->data = data;
        }
};
void LevelOrder(GenericTree *root){
    queue<GenericTree *> q;
    GenericTree *temp;
    q.push(root);
    while (!q.empty()){
        int n = q.size();      
        while (n > 0){
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            for (int i = 0; i < temp->child.size(); i++){
                q.push(temp->child[i]);
            }
            n--;
        }
        cout << endl;
    }
    
}
int sumOfNodes(GenericTree *root){
    if(!root)
        return 0;
    int sum = root->data;
    for (int i = 0; i < root->child.size(); i++)
        sum += sumOfNodes(root->child[i]);
    return sum;
}
int main(){

    /*   Let us create below tree 
    *              10 
    *        /   /    \   \ 
    *        2  34    56   100 
    *       / \         |   /  | \ 
    *      77  88       1   7  8  9 
    */

    GenericTree *root = new GenericTree(10);
    (root->child).push_back(new GenericTree(2));
    (root->child).push_back(new GenericTree(34));
    (root->child).push_back(new GenericTree(56));
    (root->child).push_back(new GenericTree(100));
    (root->child[0]->child).push_back(new GenericTree(77));
    (root->child[0]->child).push_back(new GenericTree(88));
    (root->child[2]->child).push_back(new GenericTree(1));
    (root->child[3]->child).push_back(new GenericTree(7));
    (root->child[3]->child).push_back(new GenericTree(8));
    (root->child[3]->child).push_back(new GenericTree(9));

    cout << "Level order traversal : \n";
    LevelOrder(root);
    cout << "\nThe Sum of nodes of generic tree : " << sumOfNodes(root);


}