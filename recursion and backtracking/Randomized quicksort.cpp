#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Randomizedquicksort
//complexity will always be nlogn
void shuffle(int *a,int s ,int e)
{
    srand(time(NULL));
    int j;
    for(int i =e ; i>0 ; i--)
    {
        j = rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int partition(int *a,int s,int e)
{   int pivot  = a[e];
    int i = s-1;
    for(int j = s ; j<e ; j++)
    {
        if(a[j]<=pivot)
        {   i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void quick_sort(int *a,int s, int e)
{
    if(s>=e)
    return;
    int p = partition(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);
}
int main() {
   int a[] = {1,5,7,6,3,57,22,32};
   shuffle(a,0,7);
   for(int i=0 ; i<=7; i++)
   printf("%d ",a[i]);
   quick_sort(a,0,7);
   for(int i=0 ; i<=7; i++)
   printf("%d\n",a[i]);
   return 1;
}
