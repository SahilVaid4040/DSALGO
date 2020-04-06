#include <iostream>
#include <bitset>
using namespace std;
//declaring each bitset for each column and each diagonal 
bitset<30> col,dl,dr;
    void solve(int r, int n , int &ans)
    {   //base case
        if(r==n)
        {
            ans++;
            return;
        }
        //trying to place a queen at every column
        for(int i=0 ; i<n ; i++)
        {
            //check for safe position
            if(!col[i] && !dl[r-i+n-1] && !dr[r+i])
            {
                col[i] = dl[r-i+n-1] = dr[r+i] = 1;
                solve( r+1 , n, ans);
                //backtacking
                col[i] = dl[r-i+n-1] = dr[r+i] = 0;
            }
        }
    }
int main() {
                int ans =0;
                solve(0,8,ans);
                printf("%d",ans);
                 return 1;
}
