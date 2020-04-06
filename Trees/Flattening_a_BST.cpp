#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data =d;
        left = NULL;
        right = NULL;
    }
};
node *insert_in_BST(node*root , int d)
{
    if(root==NULL)
    {
        return new node(d);
    }
    if(d<=root->data)
    {
        root->left = insert_in_BST(root->left,d);
        return root;
    }
    else
    {
        root->right = insert_in_BST(root->right,d);
        return root;
    }
}
node* Build_a_BST()
{
    node *root = NULL;
    int x;
    cin>>x;
    while(x!=-1)
    {
       root = insert_in_BST(root,x);
       cin>>x;
    }
    return root;
}
void BFS(node *root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *f = q.front();
        if(f==NULL)
        {
            cout<<"\n";
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
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
class LinkedList
{
    public:
    node* head;
    node* tail;
};
LinkedList Flatten_a_BST(node*root)
{   LinkedList l;
    //NULL Node
    if(root==NULL)
    {
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    //leaf node(head and tail will be node itself)
    if(root->left==NULL && root->right==NULL)
    {
        l.head = root;
        l.tail = root;
        return l;
    }
    //only left Subtree
    if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftlist = Flatten_a_BST(root->left);
        leftlist.tail->right = root;
        l.head = leftlist.head;
        l.tail = root;
        return l;
    }
    //only right Subtree
    if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightlist = Flatten_a_BST(root->right);
        root->right = rightlist.head;
        l.head = root;
        l.tail = rightlist.tail;
        return l;
    }
    //left as well as right Subtree is present
    else
    {
        LinkedList leftlist = Flatten_a_BST(root->left);
        LinkedList rightlist = Flatten_a_BST(root->right);
        l.head = leftlist.head;
        leftlist.tail->right = root;
        root->right = rightlist.head;
        l.tail = rightlist.tail;
        return l;
    }
}
int main() {
    node* root = Build_a_BST();
    BFS(root);
    LinkedList l  = Flatten_a_BST(root);
    node *temp = l.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}