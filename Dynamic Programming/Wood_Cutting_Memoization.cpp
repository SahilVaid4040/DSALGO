#include <iostream>
using namespace std;
int memo[100];
int Max_Profit(int price[100],int total_length)
{
    if(total_length==0)
    {
        return 0;
    }
    if(memo[total_length]!=-1)
    {
        return memo[total_length];
    }
    int best = 0;
    for(int i=1; i<=total_length; i++)
    {
        int current_profit = price[i]+Max_Profit(price,total_length-i);
        best = max(best,current_profit);
    }
    memo[total_length] = best;
    return best;
}
int main() {
    int total_length;
    cin>>total_length;
    int price[100];
    for(int i=0 ;i<=total_length;i++)
    {
        memo[i] = -1;
    }
    for(int i=1; i<=total_length; i++)
    {
        cin>>price[i];
    }
    cout<<Max_Profit(price,total_length);
    return 0;
}

