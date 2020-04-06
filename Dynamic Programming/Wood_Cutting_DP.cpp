#include <iostream>
using namespace std;
int Max_ProfitDP(int price[100],int total_length)
{
    int DP[100] = {};
    for(int len =1; len<=total_length; len++)
    {
        int best = 0;
        for(int cut = 1; cut<=len; cut++)
        {
            best = max(best,(price[cut]+DP[len-cut]));
        }
        DP[len] = best;
    }
    return DP[total_length];
}
int main() {
    int total_length;
    cin>>total_length;
    int price[100];
    for(int i=1; i<=total_length; i++)
    {
        cin>>price[i];
    }
    cout<<Max_ProfitDP(price,total_length);
    return 0;
}

