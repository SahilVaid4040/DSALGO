#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data =d;
        left = NULL;
        right = NULL;
    }
};
node* build_Tree()
{
    int d;
    cin>>d;
    node *root;
    if(d==-1)
    {
        return NULL;
    }
    root = new node(d);
    root->left  =build_Tree();
    root->right = build_Tree();
    return root;
}
void Vertical_Order_Print(node *root,unordered_map<int,vector<int>>&myMap,int d)
{
    if(root==NULL)
    {
        return;
    }
    myMap[d].push_back(root->data);
    Vertical_Order_Print(root->left,myMap,d-1);
    Vertical_Order_Print(root->right,myMap,d+1);

}
int Min_key(node *root)
{   
    if(root==NULL || root->left==NULL)
    {
        return 0;
    }
    return -1+Min_key(root->left);
}
int Max_key(node *root)
{   
    if(root==NULL || root->right==NULL)
    {
        return 0;
    }
    return 1+Max_key(root->right);
}
int main() {
    node *root  =build_Tree();
    unordered_map<int,vector<int>>m;
    Vertical_Order_Print(root,m,0);
    
    for(int i=Min_key(root); i<=Max_key(root); i++)
    {
        vector<int> v= m[i];
        for(int j=0 ; j<v.size(); j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
