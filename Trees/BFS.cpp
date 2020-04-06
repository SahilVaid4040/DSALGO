#include <iostream>
#include <queue>
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
void bfs(node *root)
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node *f  =q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
}
int main() {
    node *root = buildTree();
    bfs(root);
    return 0;
}
