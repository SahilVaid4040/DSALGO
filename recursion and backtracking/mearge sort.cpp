#include <iostream>
using namespace std;
void mearge(int a[],int s, int e)
{
     int mid = (s+e)/2;
     int i = s;
     int j = mid+1;
     int k =s;
     int temp[1000];
     while(i<=mid && j<=e)
     {
         if(a[i]<a[j])
         temp[k++] = a[i++];
        else 
        temp[k++] = a[j++];
     }
     while(i<=mid)
     temp[k++] = a[i++];
     while(j<=e)
     temp[k++] = a[j++];
     for(int i= s ; i<=e ; i++)
     a[i] = temp[i];
     
}
void mearge_sort(int a[],int s,int e)
{   //base case array is already split up
    if(s>=e)
    return;
    //follow 3 steps
    //divide
    int mid = (s+e)/2;
    //recursivly sort the divided arrays
    mearge_sort(a,s,mid);
    mearge_sort(a,mid+1,e);
    //mearge the divided and sorted array
    mearge(a,s,e);
}
int main() {    
    int a[] = {7,9,8,6,4,3,2,1};
    mearge_sort(a,0,7);
    for(int i = 0 ; i<=7 ; i++)
    printf("%d ",a[i]); 
    
}
