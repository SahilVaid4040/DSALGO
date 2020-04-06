#include <iostream>
using namespace std;
bool CanPlace(int mat[][9],int i,int j,int n,int number)
{
    //check for the same number in rows and columns
    for(int x=0 ; x<n ; x++)
        {
            if(mat[i][x]==number || mat[x][j]==number)
                return false;
        }   
    //for subgrid starting index of the subgrid will be(i/3)*3 and same for j
    int istart = (i/3)*3;
    int jstart = (j/3)*3;
    for(int x=istart ; x<(istart+3) ; x++)
        {
            for(int y = jstart ; y<(jstart+3) ; y++)
               { 
                   if(mat[x][y]==number)
                    return false;
               }
        }
    return true;
}
bool SolveSudoku(int mat[][9],int i,int j,int n)
 {
    //Base case
    if(i==n)
        {
            for(int i=0 ; i<n ; i++)
                {
                    for(int j=0 ; j<n ; j++)
                    {
                        printf("%d ",mat[i][j]);
                    }
                    printf("\n");
                }
            return true;
        }
    //crossed last element of the row
    if(j==n)
      return SolveSudoku(mat,i+1,0,n);
    //Any number already placed at that position we go to next position
    if(mat[i][j]!=0)
      return  SolveSudoku(mat,i,j+1,n);
    //Trying to place numers at position
    for(int number =1; number<=n; number++)
        {
            if(CanPlace(mat,i,j,n,number))
                {  //Assume number can be placed
                    mat[i][j] = number;
            
                     //if we can place the number we then check for next cell
                   bool check = SolveSudoku(mat,i,j+1,n);
                   if (check==true)
                   return true;
                }
                }       
                
                //Backtrack
                mat[i][j] = 0;
                return false;
}
int main()
{  
     int mat[9][9] = {
                    {5,3,0,0,7,0,0,0,0},
                    {6,0,0,1,9,5,0,0,0},
                    {0,9,8,0,0,0,0,6,0},
                    {8,0,0,0,6,0,0,0,3},
                    {4,0,0,8,0,3,0,0,1},
                    {7,0,0,0,2,0,0,0,6},
                    {0,6,0,0,0,0,2,8,0},
                    {0,0,0,4,1,9,0,0,5},
                    {0,0,0,0,8,0,0,7,9}
                     };
        
            SolveSudoku(mat,0,0,9);

    return 1;
}
