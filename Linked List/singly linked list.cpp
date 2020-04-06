#include <iostream>
using namespace std;
class node
{   public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
//passing the pointer variable by refrence
//if you don't pass it by refrence you will get null because the head in the
//main function will always keep on pointing towards NULL
void InsertAtHead(node *&head,int data)
{   //we make a dynamic object of node so that it is not destroyed after the executuion of this function
    node *n = new node(data);
    n->next = head;
    head = n;
}
int length(node *head)
{   int len =0;
    while(head!=NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
void InsertAtEnd(node *&head,int d)
{   if(head==NULL)
    InsertAtHead(head,d);
    else{
    node *n = new node(d);
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    }
}
void InsertAtMidle(node *&head,int d,int p){
    if((head==NULL)||(p==0))
    InsertAtHead(head,d);
    else if(p>length(head))
    InsertAtEnd(head,d);
    else{
    node *temp = head;
    while(p-1)
    {temp = temp->next;
    p--;
    }
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
    }
}

//if we pass head as refrence in this function it will work only for one time because the head will now
//be changed to NULL after the execution of this function
void print(node*head)
{   
    //node*temp = head;
    //we do not need a temp pointer because since head pointer is passed by value
    //it will  not change for the main function
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}
void deleteathead(node *&head)
{   if(head==NULL)
    return;
    else{
    node *temp = head;
    head = head->next;
    delete temp;
    }
}
void deleteatend(node *&head)
{   
    node *prev = NULL;
    node *temp = head;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}
void deleteatmidle(node *&head,int p)
{   if(head==NULL)
    return;
    else if(p==0)
    deleteathead(head);
    else
    {   node *temp1 = head;
        while(p-1){
        temp1 = temp1->next;
        p--;
        }
        node *temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;
    }
}
bool searchrecursive(node *head,int key)
{   //base case
    if(head==NULL)
    return false;
    //recursive case
    else if(head->data==key)
    return true;
    else
    searchrecursive(head->next,key);
}
bool searchiterative(node *head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
        return true;
        else
        head = head->next;
    }
    return false;
}
void BuildList(node *&head)
{
    int x;
    cin>>x;
    while(x!=-1)
    {
        InsertAtHead(head,x);
        cin>>x;
    }
}
ostream& operator<<(ostream &os,node *head)
{
   
   print(head);
   return os;
}
istream& operator >>(istream &is, node *&head)
{
    int n;
    cin>>n;
    int x;
    while(n)
    {  
        cin>>x;
        InsertAtEnd(head,x);
        n--;
    }
    return is;
}

int main() {
   node *head = NULL;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    InsertAtMidle(head,8,2);
    InsertAtEnd(head,16);
    print(head);
    deleteathead(head);
    print(head);
    deleteatend(head);
    print(head);
    deleteatmidle(head,2);
    print(head);
    if(searchiterative(head,8))
    cout<<"8 is present"<<endl;
    else
    cout<<"not present"<<endl;
    if(searchrecursive(head,8))
    cout<<"8 is present"<<endl;
    else
    cout<<"not present"<<endl;
    node *head2 = NULL;
    BuildList(head2);
    print(head2);
    cout<<head2<<head;
    node *head3 = NULL;
    node *head4 = NULL;
    cin>>head3>>head4;
    cout<<head3<<head4;
    return 0;
}
