#include <iostream>
#include <vector>
using namespace std;
template<typename t>
class stack
{
    private:
    vector<t>v;
    public:
    void push(t d)
    {
        v.push_back(d);
    }
    bool empty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!empty())
        v.pop_back();
    }
    t top()
    {
        return v[v.size()-1];
    }
};
int main() {
    stack<int>s;
    for(int i=1 ; i<=5;i++)
    s.push(i*i);
    for(int i=0 ; i<5 ; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    stack<char>c;
    //pushing A to F
    for(int i=65;i<=70;i++)
    c.push(i);
    for(int i=0 ; i<=5 ; i++)
    {
        cout<<c.top()<<" ";
        c.pop();
    }
    return 0;
}
