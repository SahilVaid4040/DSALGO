#include <iostream>
using namespace std;
long long cellProblem(int n,int x,int y,int z)
{
    //buttom's up DP
    //base case
    long long DP[100];
    DP[0]=0;
    DP[1]=0;
    for(int i=2; i<=n; i++)
    {
        if(i&1)
        {
            DP[i] = min(DP[i-1]+y,DP[(i+1)/2]+x+z);
        }
        else
        {
            DP[i] =min(DP[i/2]+x,DP[i-1]+y); 
        }
    }
    return DP[n];
}
int main() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cellProblem(n,x,y,z);
    return 0;
}

