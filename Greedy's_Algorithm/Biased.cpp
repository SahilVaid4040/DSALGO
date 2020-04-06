#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d ",&n);
    int arr[n+1]={};
    for(int i=0; i<n; i++)
    {
        int t;
        scanf("%d ",&t);
        arr[t]++;
    }
    int pos=1;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        while(arr[i]!=0)
        {
            ans+=abs(i-pos);
            pos++;
            arr[i]--;
        }
    }
    cout<<ans;
    return 0;
}
