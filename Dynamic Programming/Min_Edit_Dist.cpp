#include <iostream>
#include <cstring>
using namespace std;
int MinEditDist(char inp[101],char out[100])
{
    int DP[101][101];
    int m = strlen(inp);
    int n = strlen(out);
    DP[0][0] =0;
    //null to input
    for(int i =1; i<=m; i++)
    {
        DP[i][0] = DP[i-1][0]+1;
    }
    //null to output
    for(int j =1; j<=n; j++)
    {
        DP[0][j] = DP[0][j-1]+1;
    }
    //filing the DP table
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int q1 = DP[i-1][j-1];//replacement
            int q2 = DP[i][j-1];//insertion
            int q3 = DP[i-1][j];//deletion
            int k;
            if(inp[i-1]==out[j-1])
            {
                k=0;
            }
            else
            {
                k=1;
            }
            DP[i][j] = min(q1,min(q2,q3)) + k;
        }
    }
    return DP[m][n];
}
int main() {
    char inp[100];
    char out[100];
    cin>>inp>>out;
    cout<<MinEditDist(inp,out);
    return 0;
}

