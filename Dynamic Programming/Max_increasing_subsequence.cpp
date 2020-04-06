#include <iostream>
using namespace std;
//lis=longest increasing subsequence
int lis(int arr[100],int n)
{
    int DP[101]={};
    //base case
    for(int i=0; i<n; i++)
    {
        DP[i] =1;
    }
    int ans =0;
    for(int i=1; i<n; i++)
    {   int maxi = 0;
        for(int j=0; j<i; j++)
        {   //j th element can be absorbed bu ith element is the subsequence
            if(arr[j]<=arr[i])
            {   
                int curlen  = 1+DP[j];
                DP[i] = max(curlen,DP[i]);
            }
        }
        ans  = max(ans,DP[i]);
    }
    return ans;
}
int main() {
    int arr[] = {10,22,9,33,21,50,41,60,80,6};
    cout<<lis(arr,10);
    return 0;
}

