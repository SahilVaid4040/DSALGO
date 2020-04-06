#include <iostream>
using namespace std;
//finding pivot(greatest) element in an array using binary search
int pivotelementusingbinarysearch(int a[],int n)
{   int s =0;
        int e = n-1;
        int mid;
   while(s<e)
   {
       mid = (s+e)/2;
       //element is decreasing in a rotated sorted array that means it will be peak ie. maxima
       if(a[mid-1]>a[mid])
       {
           return a[mid-1];
       }
       //since the first condition is false it clearly indicated a[mid]>a[mid-1] so we don't
       //check for it and only check for next element ie. if a[mid]>a[m+1] indicates that a[mid] is the local maxima
       else if(a[mid+1]<a[mid])
       {
           return a[mid];
       }
       //now since we have checked for pivot element in either side left or right of mid
       //pivot element will always be on the side having discontinuity ie. unsorted array
       //first we check if the left side of the array is unsorted
       else if(a[s]>=a[mid])
       e = mid -1;
       //check for weather the right side of array is unsorted
       else if(a[mid]>=a[e])
       s = mid+1;
   }
   return -1;
}
int main() {
    int a[] = {6,7,1,2,3,4,5};
    printf("%d",pivotelementusingbinarysearch(a,7));
    return 1;
}
