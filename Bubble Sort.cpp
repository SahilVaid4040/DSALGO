#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void bubblesort(int *arr,int n)
{   
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j =0 ; j<n-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
    
}
int main() {
   int arr [8] = {5,-1,4,1,3,2,8,53};
   bubblesort(arr,8);
   for(int i =0 ; i<8 ; i++)
   cout<<arr[i]<<endl; 
}
