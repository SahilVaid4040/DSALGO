#include <iostream>
using namespace std;
int finduniqueno(int *a,int n)
{   //we count the frequency of bits of all numbers in array
    int freqbits[32]={0};
    int temp,j;
    for(int i =0; i<n; i++)
    {   temp =a[i];
        j=0;
        while(temp)
        {
            freqbits[j] += temp&1;
             temp = temp>>1;
            j++;
        }
    }
    int ans =0;
    for(int i =0; i<32 ; i++)
    //take modulus by 3 since all numbers are 3 times except one
    {freqbits[i] %= 3;
    //convert its bits to decimal
    ans += (freqbits[i]<<i);
    
    }
    return ans;
}
int main() {
    int arr[] = {1,2,3,8,1,2,3,1,2,3};
    printf("%d",finduniqueno(arr,10));
    return 0;
}
