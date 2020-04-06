#include <iostream>
using namespace std;
int minCost(int grid[][100],int m,int n)
{
    int DP[100][100];
    //Base case
    DP[0][0]= grid[0][0];
    //filling the first row
    for(int i=1; i<n;i++)
    {
    DP[0][i] = DP[0][i-1] +grid[0][i];
    }
    //filing the first column
    for(int i=1; i<m;i++)
    {
    DP[i][0] = DP[i-1][0] +grid[i][0];
    }
    for(int row =1; row<m; row++)
    {
        for(int column = 1; column<n; column++)
        {
            DP[row][column] = min(DP[row-1][column],DP[row][column-1])+grid[row][column];
        }
    }
    return DP[m-1][n-1];    
}
int main() {
    int grid[100][100] = {{1,2,3},
                    {4,8,2},
                    {1,5,3}
                    };
    cout<<minCost(grid,3,3);
    return 0;
}


