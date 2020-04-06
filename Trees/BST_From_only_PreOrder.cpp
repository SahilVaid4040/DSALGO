#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
void BFS(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        if(f==NULL)
        {
            q.pop();
            cout<<"\n";
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout<<f->data<<" ";
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
}
node* BuildTreefromTraversals(int *inOrder,int *pre,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return NULL;
    }
    int index = -1;
    node* root = new node(pre[i]);
    for(int j=s ; j<=e ; j++)
    {
        if(pre[i]==inOrder[j])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = BuildTreefromTraversals(inOrder,pre,s,index-1);
    root->right = BuildTreefromTraversals(inOrder,pre,index+1,e);
    return root;
}
int main() {
    int n;
    cin>>n;
    int pre[10];
    int inOrder[10];
    for(int i=0 ; i<n ; i++)
    {
        cin>>pre[i];
        inOrder[i] = pre[i];
    }
    sort(inOrder,inOrder+n);
    //InOrder of a BST can be obtained by sorting the preorder/postorder
    node* root = BuildTreefromTraversals(inOrder,pre,0,n-1);
    BFS(root);
    return 0;
}
