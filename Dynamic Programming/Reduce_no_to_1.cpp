#include <iostream>
using namespace std;
const int inf = (int)1e9;
int memo[10000];
int reduce_no(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(memo[n]!=-1)
    {
        return memo[n];
    }
    int q1 = inf, q2 = inf, q3 = inf;
    if(n%3==0)
    {
        q1 = 1+reduce_no(n/3);
    }
    if(n%2==0)
    {
        q2 = 1+reduce_no(n/2);
    }
    q3 = 1+reduce_no(n-1);
    //memoize
    memo[n] = min(q1,min(q2,q3));
    return memo[n];
}
int main() {
    int n;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        memo[i] = -1;
    }
    cout<<reduce_no(n);
    return 0;
}

