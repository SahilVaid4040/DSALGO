#include <iostream>
#include <climits>
using namespace std;
int DP[16][4];
int n =4;
int dist[10][10] = {{0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {25,34,10,0}};
int visited_All = (1<<n)-1;
int Travelling_salesman_problem(int mask,int pos)
{   //Base Case
    if(mask==visited_All)
    {
        return dist[pos][0];
    }
    int Ans =INT_MAX;
    if(DP[mask][pos]!=-1)
    {
        return DP[mask][pos];
    }
    //Try to go to unvisited city
    for(int city = 0 ; city<n ;city++)
    {   //checking city is not visited
        if((mask&(1<<city))==0)
        {
            int New_ans = dist[pos][city] + Travelling_salesman_problem((mask|(1<<city)),city);
            Ans=min(Ans,New_ans);
        }
    }
    return DP[mask][pos] = Ans;
}
int main() {
    for(int i=0; i<16 ;i++)
    {
        for(int j=0; j<4; j++)
        {
            DP[i][j] = -1;
        }
    }
    cout<<Travelling_salesman_problem(1,0);
    return 0;
}
