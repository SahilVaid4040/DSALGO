#include <iostream>
#include <climits>
using namespace std;
int arr[1000];
long long DP[1000][1000];
long long sum(int s,int e)
{
    long long ans = 0;
    for(int i=s; i<=e; i++)
    {
        ans+=arr[i];
        ans%=100;
    }
    return ans;
}
long long solveMixtures(int s,int e)
{   //base case
    if(s>=e)
    {
        return 0;
    }
    if(DP[s][e]!=-1)
    {
        return DP[s][e];
    }
    DP[s][e] = INT_MAX;
    for(int k=s; k<=e; k++)
    {
        DP[s][e] = min(DP[s][e],solveMixtures(s,k)+solveMixtures(k+1,e)+sum(s,k)*sum(k+1,e));
    }
    return DP[s][e];
}
int main() {
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                DP[i][j]=-1;
            }
        }
        cout<<solveMixtures(0,n-1)<<"\n";
    }
    return 0;
}

