#include <iostream>
using namespace std;
//arrange the tiles in a wall of (4XN) size of tile is (4X1)
int tiling(int n)
{   //for 4 ans will be 2 as only 2 cases either arrange tiles vertically or horizontally
    if(n==4)
    return 2;
    //if n<4 only 1 way to arrange the tiles vertically
    if(n<4)
    return 1;
    int x = tiling(n-1);
    int y = tiling(n-4);
    return(x+y);
}
int main() {
    printf("%d ",tiling(5));
}
