#include <iostream>
using namespace std;
int dp[100] ={0};
//No of BST is catalans number
int Catalans_Number(int n)
{
     if(n==0)
     {
         return 1;
     }
     if(dp[n]!=0)
     {
         return dp[n];
     }
     int ans=0;
     for(int i=1 ; i<=n ; i++)
     {
         ans+=Catalans_Number(i-1)*(Catalans_Number(n-i));
     }
     dp[n] = ans;
     return ans;
}
int main() {
    cout<<"First five catalans number\n";
    for(int i=0 ; i<5 ; i++)
    {
        cout<<Catalans_Number(i)<<" ";        
    }
    
    return 0;
}
