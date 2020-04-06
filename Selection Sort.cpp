#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void selectionsort(int *arr,int n)
{   int minindex;
    for(int i=0 ; i<n-1 ; i++)
    {   minindex = i;
        //min = a[i];
        for(int j =i+1 ; j<n ; j++)
        {
            if(arr[minindex]>arr[j]){
            minindex =j;
            }
        }
        swap(&arr[i],&arr[minindex]);
    }
    
}
int main() {
   int arr [8] = {5,-1,4,1,3,2,8,53};
   selectionsort(arr,8);
   for(int i =0 ; i<8 ; i++)
   cout<<arr[i]<<endl; 
}
