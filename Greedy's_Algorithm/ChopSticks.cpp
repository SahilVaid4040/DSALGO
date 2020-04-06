#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d ",&n);
    int k;
    scanf("%d ",&k);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d ",&arr[i]);
    }
    sort(arr,arr+n);
    int ans=0;
    for(int i=0; i<(n-1); i++)
    {
        if((arr[i+1]-arr[i])<=k)
        {
            ans++;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
