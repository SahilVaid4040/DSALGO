#include <iostream>
using namespace std;
//Buttom-Up fibbonaci
int fib(int n)
{
int DP[1000] ={};
DP[0]=0;
DP[1] = 1;
for(int cur_no=2; cur_no<=n; cur_no++)
{
DP[cur_no] = DP[cur_no-1]+DP[cur_no-2];
}
return DP[n];
}
int main() {
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}

