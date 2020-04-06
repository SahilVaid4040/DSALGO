#include <iostream>
#include <cstring>
using namespace std;
int memo[100][100];
int Max_Profit(int arr[100],int be,int en,int year)
{ 
    if(be>en)
    {
        return 0;
    }
    if(memo[be][en]!=-1)
    {
        return memo[be][en];
    }
    int q1 = arr[be]*year + Max_Profit(arr,be+1,en,year+1);
    int q2 = arr[en]*year + Max_Profit(arr,be,en-1,year+1);
    int ans = max(q1,q2);
    memo[be][en] = ans;
    return ans;
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<Max_Profit(arr,0,n-1,1);
    return 0;
}

