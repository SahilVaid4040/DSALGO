#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int lcm(int a, int b){
return (a*b)/gcd(a,b);
}
int main() {
    printf("%d ",gcd(10,15));
    printf("%d ",lcm(10,15));

}
