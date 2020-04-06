#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void BFS(node *root)
{   queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {   node *f = q.front();
        if(f==NULL)
        {
            cout<<"\n";
            q.pop();
            if(!q.empty())
            q.push(NULL);
        }
        else
        {q.pop();
        cout<<f->data<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
        }
    }
}
node *Insert_in_BST(node *root,int d)
{
    //Base Case
    if(root==NULL)
    {
    return new node(d);
    }
    if(d<=root->data)
    root->left = Insert_in_BST(root->left,d);
    else
    root->right = Insert_in_BST(root->right,d);
    return root;
}
node *Build_BST()
{
    int d;
    cin>>d;
    node *root = NULL;
    while(d!=-1)
    {
        root = Insert_in_BST(root,d);
        cin>>d;
    }
    return root;
}
void InOrderPrint(node *root)
{
    //Base case
    if(root==NULL)
    return;
    InOrderPrint(root->left);
    cout<<root->data<<" ";
    InOrderPrint(root->right);
}
int main() {
    node *root = Build_BST();
    BFS(root);
    InOrderPrint(root);
    return 0;
}
