#include <iostream>
using namespace std;
class node
{
public:
int data;
node *right;
node *left;
node(int d)
{
data =d;
right = NULL;
left = NULL;
}
};
node *buildTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    node *root = new node(x);
    root->left =  buildTree();
    root->right = buildTree();
    return root;
}
//preorder print
void printPre(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}
//inorder Print
void printIn(node *root)
{
    if(root==NULL)
    return;
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
//post order print
void printPost(node *root)
{
    if(root==NULL)
    return;
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
int main() {
    node *root = buildTree();
    printPre(root);
    cout<<"\n";
    printIn(root);
    cout<<"\n";
    printPost(root);
    return 0;
}
