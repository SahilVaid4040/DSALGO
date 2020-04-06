#include <iostream>
#include <algorithm>
using namespace std;
void Triplets(int arr[100],int n,int target)
{   
    for(int i=0; i<n-2; i++)
    {
        int l = i+1;
        int r = n-1;
        int target1 = (target-arr[i]);
        while(l<r)
        {
            if((arr[l]+arr[r])==target1)
            {
                cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<"\n";
                l++;
                r--;
            }
            else if((arr[l]+arr[r])<target1)
            {
                l++;
            }
            else if((arr[l]+arr[r])>target1)
            {
                r--;
            }
        }
    }
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        scanf("%d ",&arr[i]);
    }
    int target;
    cin>>target;
    sort(arr,arr+n);
    Triplets(arr,n,target);
    return 0;
}
