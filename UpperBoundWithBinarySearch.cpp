#include <iostream>
using namespace std;
//upperbound by binary search
//The key concept here is once a element is found we search in right half of array
int upperboundbs(int a[], int n , int key)
{   int s = 0 ;
    int e = n-1;
    int mid;
    int ans =-1;
    while(s<=e)
    {   mid = (s+e)/2;
        if(a[mid]==key)
        {   ans = mid;
             s = mid+1;
             }
        else if (a[mid]>key)
        e = mid-1;
        else if(a[mid]<key)
        s = mid+1;
    }
    return ans;
}
int main() {
    int arr[] ={1,2,3,4,7,7,7};
    int key = 7;
    printf("%d last found at index %d",key, upperboundbs(arr,7,key));
}
