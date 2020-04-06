#include <iostream>
using namespace std;
int pivot(int *arr,int s,int e)
{
    int p = arr[s];
    int i =s;
    for(int j=s+1;j<=e;j++)
    {
        if(arr[j]<p)
        {
            swap(arr[i+1],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[s]);
    return i;
}
void Quick_Sort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p = pivot(arr,s,e);
    Quick_Sort(arr,s,p-1);
    Quick_Sort(arr,p+1,e);
}
int main() {
    int arr[] = {7,1,3,5,4,2,6};
    Quick_Sort(arr,0,6);
    for(int i=0 ;  i<7; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
