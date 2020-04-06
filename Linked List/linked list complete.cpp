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
node* reverserecursive(node *head)
{   
    //base case
    if(head->next==NULL || head == NULL)
    return head;
    //recursive case
    node *smallhead = reverserecursive(head->next);
    node *c  = head;
    c->next->next = c;
    c->next = NULL;
    return smallhead;
}
node* mid_pt(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node* knodefromlast(node *head,int k)
{
    node *r1 = head;
    while(k-1){
    r1 = r1->next;
    k--;
    }
    node *r2 = head;
    while(r1->next!=NULL)
    { 
        r1 = r1->next;
        r2 = r2->next;
        
    }
    return r2;
}
node *megresortedlist(node *l1,node *l2)
{
    //Base case
    if(l1 ==NULL)
    return l2;
    else if(l2==NULL)
    return l1;
    //recursive case
    node *n1;
    if(l1->data<l2->data)
    {
        n1 = l1;
        n1->next = megresortedlist(l1->next,l2);
    }
    else if(l1->data>l2->data)
    {
        n1 = l2;
        n1->next = megresortedlist(l1,l2->next);
    }
    return n1;
}
//mearge sort on a LL
node* mergesort(node *head)
{   //base case
    if(head==NULL || head->next==NULL)
    return head;
    //recursive case
    node *mid = mid_pt(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = mergesort(a);
    b = mergesort(b);
    node *c = megresortedlist(a,b);
    return c;
}
bool Detect_Cycle(node *head)
{   //if slow and fast pointer meet its a cycle
    node *fast = head;
    node *slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow=  slow->next;
        if(fast==slow)
        return true;
    }
    return false;
}
//detection is same to remove we just move slow pointer to head and inititalize a temporary pointer to fast pointer
//now we move both slow and fst pointer by once stem but not the temproary pointer to maintain gap of one between temporary and fast pointer
//now we move all the three slow fast and temporary pointer by 1 step till fast is not equal to slow which will be the point where loop terminates
//now we make the next of temp to null to break the cycle read floyd's cycle from notes
void Detect_And_Remove_cycle(node *head)
{
    bool cycle = false;
    node *fast = head;
    node *slow = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow=  slow->next;
        if(fast==slow)
        {cycle = true;
        break;}
    }
    if(cycle)
    {
        slow = head;
        node *temp = fast;
        slow  =slow->next;
        fast = fast->next;
        while(slow!=fast)
        {
        slow  =slow->next;
        fast = fast->next;
        temp = temp->next;
        }
        temp->next=NULL;
    }
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
    head4 = reverserecursive(head4);
    cout<<head4;
    node *mid = mid_pt(head4);
    cout<<(mid->data)<<endl;
    node *k = knodefromlast(head4,4);
    cout<<(k->data)<<endl;
    node *head5 = NULL;
    node *head6 = NULL;
    cin>>head5>>head6;
    node *head7 =megresortedlist(head5,head6);
    cout<<head7;
    node *head8 = NULL;
    cin>>head8;
    head8 = mergesort(head8);
    cout<<head8;
    cout<<Detect_Cycle(head8)<<endl;
    //creating a test case with cycle
    node *head9 = head8;
    while(head9->next!=NULL)
    {
        head9 = head9->next;
    }
    head9->next = mid_pt(head8);
    cout<<Detect_Cycle(head8)<<endl;
    Detect_And_Remove_cycle(head8);
    cout<<head8;
    return 0;
}
