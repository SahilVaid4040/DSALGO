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
    q.push(NULL);
    while(!q.empty())
    {
        node *f  =q.front();
        //every time we see NULL we change line
        if(f==NULL)
        {
            cout<<"\n";
            q.pop();
            //if row is not empty then we push another NULL(since queue will be empty in the last iteration)
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
        q.pop();
        cout<<f->data<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
        }
        
    }
}

int Count(node *root)
{
    //base case
    if(root==NULL)
    return 0;
    //recursive case
    //complexity O(N)
    return 1 + Count(root->left) + Count(root->right);
}
int Sum(node *root)
{
    //Base case
    if(root==NULL)
    return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}
int Height(node *root)
{
    if(root==NULL)
    return 0;
    int h1 = Height(root->left);
    int h2 = Height(root->right);
    return 1+max(h1,h2);
}
int Diameter(node *root)
{
    if(root==NULL)
    return 0;
    int op1 = Height(root->left)+ Height(root->right);
    int op2 = Diameter(root->left);
    int op3 = Diameter(root->right);
    return max(op1,max(op2,op3));
}
int main() {
    node *root = buildTree();
    bfs(root);
    cout<<Count(root)<<"\n";
    cout<<Sum(root)<<"\n";
    cout<<Diameter(root);
    return 0;
}
