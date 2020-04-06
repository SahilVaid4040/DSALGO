#include <iostream>
#include <cstring>
using namespace std;
//largest common substring
int lcs(char first[100],char second[100])
{   int DP[100][100];
    int m = strlen(first);
    int n = strlen(second);
    //making first row zero
    for(int i=0; i<=m; i++)
    {
        DP[i][0]=0;
    }
    //making column zero
    for(int j=0; j<=n; j++)
    {
        DP[0][j] = 0;
    }
    for(int i=1;i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(first[i-1]==second[j-1])
            {
                DP[i][j] = 1+DP[i-1][j-1];
            }
            else
            {
                DP[i][j]= max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return DP[m][n];
}
int main() {
    char first[100];
    char second[100];
    cin>>first>>second;
    cout<<lcs(first,second);
    return 0;
}

