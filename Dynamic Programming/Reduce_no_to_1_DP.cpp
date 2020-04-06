#include <iostream>
#include <climits>
using namespace std;
int reduced_No_DP(int n)
{
    int DP[10000];
    DP[0]=0; DP[1]=0;
    DP[2]=1; DP[3]=1;
    for(int cur_no=4; cur_no<=n; cur_no++)
    {
        int q1 = INT_MAX;
        int q2 = INT_MAX;
        int q3 = INT_MAX;
        if(cur_no%3==0)
        {
            q1 = 1+DP[cur_no/3];
        }
        if(cur_no%2==0)
        {
            q2 = 1+DP[cur_no/2];
        }
        q3 = 1+DP[cur_no-1];
        DP[cur_no] = min(q1,min(q2,q3));
    }
    return DP[n];
}
int main() {
    int n;
    cin>>n;
    cout<<reduced_No_DP(n);
    return 0;
}

