#include <iostream>
#include <unordered_map>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int d)
    {
        data =d;
        next = NULL;
    }
};
bool Detect_Cycle(node *head)
{
    unordered_map<node*,bool>m;
    node *temp =head;
    while(temp!=NULL)
    {
        if(m[temp]==true)
        {
            cout<<"Cycle Found";
            return true;
        }
        m[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main() {
    node *head = new node(5);
    head->next = new node(10);
    head->next->next = new node(15);
    head->next->next->next = new node(20);
    head->next->next->next->next = head->next;
    cout<<Detect_Cycle(head);
    return 0;
}
