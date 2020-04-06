#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int>s;
    for(int i=1; i<=5;i++)
    s.push(i*i);
    stack<int>s1;
    int x;
    int n = s.size();
    for(int i=0 ; i<n;i++)
    {
        x = s.top();
        s.pop();
        for(int j=0 ; j<n-i-1;j++)
        {
            s1.push(s.top());
            s.pop();
        }
        s.push(x);
        for(int j=0 ; j<n-i-1;j++)
        {
            s.push(s1.top());
            s1.pop();
        }
        
    }
    for(int i=1 ; i<=5; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
