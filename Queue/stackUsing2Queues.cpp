#include <iostream>
#include <queue>
using namespace std;
class stackusing2queue
{
queue<int> *q1,*q2;
public:
stackusing2queue(){

q1 = new queue<int>();
q2 = new queue<int>();
}
void push(int x)
{
    q1->push(x);
}
void pop()
{   int n = q1->size();
    for(int i=0 ; i<n-1;i++)
    {
        q2->push(q1->front());
        q1->pop();
    }
    q1->pop();
    swap(q1,q2);
}
int top()
{
    int topelement;
    int n = q1->size();
    for(int i=0 ; i<n-1;i++)
    {
        q2->push(q1->front());
        q1->pop();
    }
    topelement = q1->front();
    q2->push(topelement);
    q1->pop();
    swap(q1,q2);
    return topelement;
}
};
int main() {
    stackusing2queue s1;
    for(int i =1; i<=5 ; i++)
    s1.push(i*i);
    for(int i =1; i<=5 ; i++)
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    
    return 0;
}
