#include <iostream>
using namespace std;
int Max_Profit(int arr[100],int n)
{   int year =n;
    int DP[100][100];
    //filling the diagonals of the matrix
    //ie. cost if bottle is sold int the 5th year
    for(int i=0; i<n; i++)
    {
        DP[i][i] = arr[i]*year; 
    }
    year--;
    //level denotes the no of bottle sold
    for(int level =2; level<=n; level++)
    {
        int start =0;
        int end = n-level;
        while(start<=end)
        { int end_window = start+level-1;
            DP[start][end_window] = max(
                (year*arr[start]+DP[start+1][end_window]),
                (year*arr[end_window]+DP[start][end_window-1])
            );
            start++;
        }
        year--;
    }
    return DP[0][n-1];
}
int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<Max_Profit(arr,n);
}

