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
int main() {
   node *head = NULL;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    print(head);
}
