#include <iostream>
using namespace std;
bool issorted(int *a,int n)
{
    if(n==1)
    return true;
    return(a[0]<=a[1]&& issorted(a+1,n-1));
    
}
int main() {
    int arr1[] = {1,2,3,3,5};
    int arr2[] = {1,2,3,7,5};
    if(issorted(arr1,5))
    printf("Arr1 is sorted");
    else 
    printf("Arr1 is not sorted");
    if(issorted(arr2,5))
    printf("Arr2 is sorted");
    else 
    printf("Arr2 is not sorted");
}
