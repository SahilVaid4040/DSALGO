#include <iostream>
using namespace std;
void insertionsort(int *arr,int n)
{   int no;
    for(int i=1 ; i<n ; i++)
    {   no = arr[i];
        int j;
        for(j =i-1 ; j>=0 && arr[j]>no ; j--)
          arr[j+1]= arr[j];
        arr[j+1] = no;
    }
    
}
int main() {
   int arr [8] = {5,-1,4,1,3,2,8,53};
   insertionsort(arr,8);
   for(int i =0 ; i<8 ; i++)
   cout<<arr[i]<<endl; 
}
