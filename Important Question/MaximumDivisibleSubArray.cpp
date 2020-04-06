#include <iostream>
using namespace std;
int Divisible_SubArrays(int arr[1000],int n)
{
    int CommSum[1000];
    CommSum[0] = 0;
    for(int i=1; i<=n; i++)
    {
        CommSum[i] = CommSum[i-1]+arr[i-1];
    }
    for(int i=0; i<=n; i++)
    {
        CommSum[i]%=n;
    }
    int frequency[1000];
    for(int i=0; i<=n; i++)
    {
        frequency[CommSum[i]]++;
    }
    int ans =0;
    for(int i=0; i<=n; i++)
    {
        ans+=((frequency[i]*(frequency[i]-1))/2);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<Divisible_SubArrays(arr,5);
    return 0;
}
