#include <iostream>
using namespace std;
//program gives no of ways as well as prints them
bool RatInaMaze(char maze[10][10], int sol[10][10],int i,int j,int m,int n,int *a) 
            {
                //Base Case
                if(i==m && j==n){
                    sol[i][j]=1;
                    for(int i=0 ; i<=m ; i++){
                        for(int j=0 ; j<=n ; j++)
                        printf("%d ",sol[i][j]);
                        printf("\n");
                    }
                    printf("\n");
                    (*a)++;
                    return true;
                }
                //Rat should not go out of maze
                if(i>m || j>n)
                return false;
                //Rat should not go on prohibited points
                if(maze[i][j]=='X')
                return false;
                //lets assume that we can move
                sol[i][j]=1;
                bool RightSidePossible = RatInaMaze(maze,sol,i,j+1,m,n,a);
                bool DownSidePossible = RatInaMaze(maze,sol,i+1,j,m,n,a);
                if(RightSidePossible || DownSidePossible)
                return true;
                //Backtrack
                sol[i][j] = 0;
                return false;
            }
int main() {
        char maze [10][10] = {
                                "0000",
                                "00X0",
                                "000X",
                                "0X00",
        };
        int sol [10][10]= {0};
        int ways =0;
        bool ans = RatInaMaze(maze,sol,0,0,3,3,&ways);
        printf("%d ways",ways);
        if(ans == false)
        printf("No Way exists");
        return 1;
}
