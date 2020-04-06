#include <iostream>
using namespace std;
//wavesortisallaboutcreatinglocalmaximaateveryevenposition
int main() {
    int arr[] = {3,4,1,54,3,78,-1,35};
    int n = sizeof(arr)/sizeof(int);
    for(int i =0 ; i<n ; i+=2)
    {
        //checking for left element
        if(i>0 && arr[i] < arr[i-1])
        swap(arr[i],arr[i-1]);
        //checking for right element
        if(i<n-1 && arr[i]<arr[i+1])
        swap(arr[i+1],arr[i]);
    }
    for(int i =0 ; i<n ; i++)
    cout<<arr[i]<<endl;
    return 0;
}
