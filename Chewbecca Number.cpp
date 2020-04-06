#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long int i = 923456789;
    int maxi = 0;
    int place =0;
    long long int j=i;
    while(j)
    {
        j = j/10;
        place++;
    }
    j =i;
    int place1=0;
    long long int ans =0;
    int x=0;
    while(j)
    {
        x = j%10;
        if(x<5 || (x==9 && place1==place-1))
        {
        ans  = ans+x*pow(10,place1);
        
        }
        else
        ans  = ans+(9-x)*pow(10,place1);
        place1++;
        j/=10;
    }
    cout<<ans;
    return 0;
}
