#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int>s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    for(auto x:s)
    cout<<x<<" "<<endl;
    for(int x:s)
    cout<<x<<endl;
    //iterators are like pointers
    for(set<int>::iterator it= s.begin(); it!=s.end();it++)
    cout<<*it<<endl;
    s.erase(5);
    for(auto x:s)
    cout<<x<<" "<<endl;
    
    return 0;
}
