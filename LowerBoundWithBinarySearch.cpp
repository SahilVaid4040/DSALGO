#include <iostream>
using namespace std;
//lowerbound by binary search
//The key formula here is that once the element is found we search again in the left half of the array
int lowerboundbs(int a[], int n , int key)
{   int s = 0 ;
    int e = n-1;
    int mid;
    int ans =-1;
    while(s<=e)
    {   mid = (s+e)/2;
        if(a[mid]==key)
        {   ans = mid;
             e = mid-1;
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
    printf("%d first found at index %d",key, lowerboundbs(arr,7,key));
}
