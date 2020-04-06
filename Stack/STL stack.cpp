#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string>s;
    s.push("Apple");
    s.push("Guava");
    s.push("Orange");
    s.push("Kiwi");
    //the top function returns the element at the top but
    //doesn't removes it whereas the pop function removes it
    //but doesn't returns anything
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
