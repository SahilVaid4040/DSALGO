#include <iostream>
using namespace std;
//function checks weather it is safe to insert the queen at given position
bool positionCheck(int board[10][10],int i,int j,int n)
{
    //checking for the column
    for(int y=0 ; y<i ; y++){
        if(board[y][j]==1)
        return false;
    }
    //checking for the left diognal
    int x =j;
    int y = i;
    while(x>=0 && y>=0){
        if(board[y][x]==1)
        return false;
        x--;
        y--;
    }
    //checking for the right diognal
    x =j;
    y = i;
    while(x<n && y>=0){
        if(board[y][x]==1)
        return false;
        x++;
        y--;
    }
    return true;
}
bool Nqueen(int board[10][10],int i,int n)
{
    //i is the place till where the board is sorted
    //n is the size of board recquired
    //base case
    if(i==n)
    {
        for(int i=0; i<n ; i++){
            for(int j=0 ; j<n; j++){
                    if(board[i][j]==1)
                    printf("Q");
                    else
                    printf(" _ ");
            }
            cout<<endl;
        }
    return true;
    }
    //Recursive case
    for(int j=0 ; j<n ; j++){
        if(positionCheck(board,i,j,n)){
            //place the queen
            board[i][j]=1;
            bool rakhsaktehain = Nqueen(board,i+1,n);
            if(rakhsaktehain)
            return true;
            else 
            board[i][j]=0;
        }
    }
    return false;
}
int main() {
    //initialize a 10X10 board with zeros
    int board[10][10] = {0};
    Nqueen(board,0,10);
}
