#include <iostream>
using namespace std;
//question was to find the number of sub arrays having sum multiple of size of original array
//the key concept here was first creating a sum array if(a[i]-a[j])%n =0 means subarray from i+1 to j
//has a sum divisble by n (a[i]- a[j])%n =0 implies a[i]%n = a[j]%n 
//so we first make a current sum array and then % it with n and then make a frequency array for all elements
//if an element comes n times in the current sum array ie. if there are n elements for which current sum is same 
// we can select any two from the n by nc2 combinations 
//frecquency of 0 is kept as 1 so that we can take a sub array of a[1] for cases when any element itself in the original array is divisible 
//by n
//calculating nc2
int nc2(int n)
{   
    int ans = n*(n-1)/2;
    return ans;
}

int specialsubarray(int a[],int n)
{
  //creating the current sum array
    for(int i =1 ; i<n ; i++)
    {
        a[i]+=a[i-1];
    }
    //taking modulus of subarray by n
    for(int i =0 ; i<n ; i++)
    {
        a[i] %= n;
        
    }
    //any no %n can only vary from 0 to n-1
    //since we have taken % with n all the numbers of the array will vary only from 0 - n-1
    //so we make frequency  array of size n
    int freq[n] = {0};
    freq[0] =1;
    for(int i=0; i<n ; i++)
       { freq[a[i]]++;
       
       }
       int ans =0;
    for(int i =0 ; i<n ; i++)
    ans += nc2(freq[i]);
    return ans;
}
int main() {
    int arr[] = {5,5,5,5,5};
    printf("%d  is the total number of unique subarrays",specialsubarray(arr,5));

    return 0;
}
