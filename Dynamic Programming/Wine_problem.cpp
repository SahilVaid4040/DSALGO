#include <iostream>
using namespace std;
int Max_Profit(int arr[100],int be,int en,int year)
{
    if(be>en)
    {
        return 0;
    }
    int q1 = arr[be]*year + Max_Profit(arr,be+1,en,year+1);
    int q2 = arr[en]*year + Max_Profit(arr,be,en-1,year+1);
    int ans = max(q1,q2);
    return ans;
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<Max_Profit(arr,0,n-1,1);
    return 0;
}

