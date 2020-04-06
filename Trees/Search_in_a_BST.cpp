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
        data =d;
        left = NULL;
        right = NULL;
    }
};
node* Insert_in_BST(node *root,int d)
{
    if(root==NULL)
    return new node(d);
    if(d<=root->data)
    root->left = Insert_in_BST(root->left,d);
    else
    root->right = Insert_in_BST(root->right,d);
    return root;
}
node* Build_a_BST()
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
void InOrder_Print(node *root)
{
    if(root==NULL)
    return;
    InOrder_Print(root->left);
    cout<<root->data<<" ";
    InOrder_Print(root->right);
}
void BFS(node *root)
{
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    node *f;
    while(!q.empty())
    {
    f = q.front();
    if(f==NULL)
    {
        cout<<"\n";
        q.pop();
        if(!q.empty())
        q.push(NULL);
    }
    else
    {
    cout<<f->data<<" ";
    q.pop();
    if(f->left)
    q.push(f->left);
    if(f->right)
    q.push(f->right);
    }
    }
}
bool Search_in_BST(node *root,int d)
{
    if(root==NULL)
    return false;
    if(root->data==d)
    return true;
    if(d<=root->data)
    return Search_in_BST(root->left,d);
    else
    return Search_in_BST(root->right,d);
}
int main() {
    node *root =Build_a_BST();
    BFS(root);
    InOrder_Print(root);
    cout<<"\n";
    int s;
    cin>>s;
    if(Search_in_BST(root,s))
    cout<<s<<" is present\n";
    else
    cout<<s<<" is not present\n";
    return 0;
}
