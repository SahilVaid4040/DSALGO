#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int main() {
    int m; 
    int n;
    scanf("%d %d",&m, &n);
    int arr [m][n];
    for(int i =0; i<m ; i++)
    {
        for(int j = 0 ; j<n ; i++)
        {
            scanf("%d ",&arr[i][j]);
        }
    }
    for(int j =0; j<n ; j+=2)
    {
        for(int i = 0 ; i<m ; i++)
        {
            if(i>0 && arr[i][j]<arr[i+1][j])
            {
                swap(&arr[i][j],&arr[i+1][j]);
            }
            else if(i<n-1 && arr[i][j]<arr[i-1][j])
            swap(&arr[i][j],&arr[i-1][j]);
        }
        
    }
    return 0;
}
