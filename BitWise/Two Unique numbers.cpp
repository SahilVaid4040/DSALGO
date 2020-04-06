#include <iostream>
using namespace std;
void twouniquenumbers(int *a,int n)
{   //first we XOR all the numbers of arrays to obtain a^b since all other numbers are repeated twice
    //all will cancel
    int res = 0;
    for(int i=0; i<n; i++)
    {
        res^=a[i];
    }
    int temp = res;
    int i=0;
    //now we try to obtain the first position where a^b is not zero
    while(temp>0)
    {
        if(temp &1)
        break;
        else
        {
            i++;
            temp>>1;
        }
    }
    //we make a mask of all\bits zero except the first bit where a^b is not zero
    int mask = 1<<i;
    int firstno = 0;
    //the first non zero bit will come from only one of two diffrent numbers
    //we xor all the numbers having the same bit all others will cancel and we will get one of two
    //unique numbers
    for(int i =0 ; i<n ; i++)
    {
        if(mask&a[i])
        firstno^=a[i];
    }
    //we know a^(a^b) = b
    //therefore we also get our second number
    int secondno = firstno^res;
    printf("First no %d\n",firstno);
    printf("Second no %d\n",secondno);

}
int main() {
    int arr[] = {1,2,3,4,5,6,4,3,2,1};
    twouniquenumbers(arr,10);
    return 0;
}
