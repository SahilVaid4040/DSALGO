#include <iostream>
using namespace std;
//To find the square root of a given number we first find it's integer part and then
//we interate for its precision in its floating point
//time complexity is equal to log2(No)+P
float squareroot(int no, int p)
{   int s =0;
    int e =no;
    int mid;
    float ans;
    //the process to find the integer part is the same as binary search 
    while(s<=e)
    {  mid = (s+e)/2;
        if(mid*mid==no)
        {
            ans = mid;
            break;
        }
        else if(mid*mid<no)
        {   ans = mid;
            s = mid+1;
        }
        else if(mid*mid>no)
        e = mid-1;

    }
    //since we have already found the integer part we will now try to find the floating part
    //we use for loop to find the floating part
    float inc  = 0.1;
    for(int i = 0; i<p ; i++)
    {   
        //we add increment factor(0.1 initially) to the integer part will the square gets greater than no 
        //once it gets greater than no decrease it by increment factor
        //we then divide increment factor by 10 and repeaat till precision
        while(ans*ans<=no)
        ans += inc;
        ans -= inc;
        inc/=10;
        
    }
    return ans;
}
int main() {
    int n =10;
    int p =3;
    printf("The square root of %d with %d precision is %f",n , p , squareroot(n,p));
}
