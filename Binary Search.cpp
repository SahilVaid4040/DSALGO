#include <iostream>
using namespace std;
int binarysearch(int a[], int n , int key)
{   int s = 0 ;
    int e = n-1;
    int mid;
    while(s<=e)
    {   mid = (s+e)/2;
        if(a[mid]==key)
        return mid;
        else if (a[mid]>key)
        e = mid-1;
        else if(a[mid]<key)
        s = mid+1;
    }
    return -1;
}
int main() {
    int arr[] ={1,2,3,4,5,6,7};
    int key = 4;
    printf("%d found at index %d",key, binarysearch(arr,7,key));
}
