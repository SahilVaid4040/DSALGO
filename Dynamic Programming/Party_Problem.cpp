#include <iostream>
using namespace std;
//people can go single or in pairs
int numWays(int n)
{
    int DP[1000]={};
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    for(int i=3; i<=n; i++)
    {
        DP[i] = DP[i-1]+((i-1)*DP[i-2]);
    }
    return DP[n];
}
int main() {
    int n;
    cin>>n;
    cout<<numWays(n)<<"\n";
    return 0;
}

