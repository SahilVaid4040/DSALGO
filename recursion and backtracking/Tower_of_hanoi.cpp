#include <iostream>
using namespace std;
void tower_of_hanoi(int n,char src,char help, char dest)
{
    if(n==0)
    return;
    tower_of_hanoi(n-1,src,dest,help);
    printf("disk no.%d %c >> %c\n",n,src,dest);
    tower_of_hanoi(n-1,help,src,dest);
}
int main() {
    tower_of_hanoi(3,'a','b','c');
}
