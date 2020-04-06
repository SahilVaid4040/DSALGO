#include <iostream>
using namespace std;
int mem[1000];
int fib(int n)
{
    if(n==0)
    {
        return  0;
    }
    if(n==1)
    {
        return 1;
    }
    if(mem[n]!=-1)
    {
        return mem[n];
    }
    int ans  = fib(n-1)+fib(n-2);
    return mem[n] = ans;
    }
int main() {
    int n;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        mem[i]=-1;
    }
    cout<<fib(n);
    return 0;
}

