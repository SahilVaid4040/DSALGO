#include <iostream>
#include <stack>
using namespace std;
void insertAtbuttom(stack<int>&s,int x)
{
    if(s.empty())
    {
    s.push(x);
    return;
    }
    int temp = s.top();
    s.pop();
    insertAtbuttom(s,x);
    s.push(temp);
}
void reversestack(stack<int>&s1)
{
    if(s1.empty())
    return;
    int x = s1.top();
    s1.pop();
    reversestack(s1);
    insertAtbuttom(s1,x);
}
int main() {
   stack<int>s;
   for(int i=1 ; i<=5 ; i++)
   s.push(i*i);
   reversestack(s);
   for(int i=1; i<=5 ; i++)
   {
    cout<<s.top()<<" ";
    s.pop();
   }
   return 0;
}
