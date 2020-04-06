#include <iostream>
#include <cstring>
int DP[100][100];
int numWays(int row,int column)
{
    //base case
    if(DP[0][0]==-1)
    {
        return 0;
    }
    for(int i=0; i<row;i++)
    {
        if(DP[i][0]==-1)
        {
            break;
        }
        DP[i][0] =1;
    }
    for(int j=0; j<column;j++)
    {
        if(DP[0][j]==-1)
        {
            break;
        }
        DP[0][j] =1;
    }
    //computing the answer
    for(int i=1; i<row; i++)
    {
        for(int j=1; j<column;j++)
        {
            if(DP[i][j]==-1)
            {
                continue;
            }
            DP[i][j]=0;
            if(DP[i][j-1]!=-1)
            {
                DP[i][j] = DP[i][j-1];
            }
            if(DP[i-1][j]!=-1)
            {
                DP[i][j] = DP[i][j]+DP[i-1][j];
            }
        }
    }
    if(DP[row-1][column-1]==-1)
    {
        return 0;
    }
    return DP[row-1][column-1];
}
using namespace std;
int main() {
    memset(DP,0,sizeof(DP));
    int m,n,p;
    cin>>m>>n>>p;
    while(p)
    {
        int x,y;
        cin>>x>>y;
        DP[x-1][y-1] = -1;
        p--;
    }
    cout<<numWays(m,n);
    return 0;
}

