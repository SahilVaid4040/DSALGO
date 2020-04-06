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
//function to build tree from in order and preorder traversals
node *buildTreeFromTraversals(int *pre,int *in,int s,int e)
{   //we can use a global variable also
    //the main purpose of using global/static i is that
    //we can give new value of i for every recusive call if i was local
    //it would be 0 for every recursive function
    static int i=0;
    //Base case
    if(s>e)
    return NULL;
    //building a node
    node *root = new node(pre[i]);
    int index =-1;
    //finding index of element in in order
    for(int j=s ; j<=e ; j++)
    {
        if(pre[i]==in[j])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = buildTreeFromTraversals(pre,in,s,index-1);
    root->right = buildTreeFromTraversals(pre,in,index+1,e);
    return root;
}

int main() {
    node *root = buildTree();
    bfs(root);
    int pre [] = {1,2,3,4,8,5,6,7};
    int in [] = {3,2,8,4,1,6,7,5};
    node *root2 =  buildTreeFromTraversals(pre,in,0,7);
    bfs(root2);
    return 0;
}
