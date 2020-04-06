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

class Pair
{
    public:
    int Height;
    bool Balanced;
};
Pair is_Balanced(node *root)
{   Pair p;
    //Base case
    if(root==NULL)
    {
        p.Height =0;
        p.Balanced = true;
        return p;
    }
    //recursive case
    Pair left_pair = is_Balanced(root->left);
    Pair right_pair = is_Balanced(root->right);
    p.Height = max(left_pair.Height,right_pair.Height)+1;
    if(abs(left_pair.Height-right_pair.Height)<=1 && left_pair.Balanced && right_pair.Balanced)
    p.Balanced = true;
    else
    p.Balanced = false;
    return p; 
}
int main() {
    node *root = buildTree();
    bfs(root);
    cout<<is_Balanced(root).Balanced<<endl;
    return 0;
}