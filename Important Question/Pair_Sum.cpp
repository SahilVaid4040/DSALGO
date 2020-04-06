#include <iostream>
#include <algorithm>
using namespace std;
int PairSum(int arr[100],int l,int r,int sum)
{
    if(l>=r)
    {
        return 0;
    }
    int k=  arr[l]+arr[r];
    if(k==sum)
    {
        return 1+PairSum(arr,l+1,r-1,sum);
    }
    if(k<sum)
    {
        return PairSum(arr,l+1,r,sum);
    }
    if(k>sum)
    {
        return PairSum(arr,l,r-1,sum);
    }
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    sort(arr,arr+n);
    for(int i=0; i<n; i++)
    {
        scanf("%d ",&arr[i]);
    }
    int sum;
    cin>>sum;
    cout<<PairSum(arr,0,n-1,sum);
    return 0;
}
