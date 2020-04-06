#include <iostream>
using namespace std;
// i denotes the place till where string is permuted
void permute(char *a , int i)
{ 
    if(a[i]=='\0')
    {
        cout<<a<<endl;
        return;
    }
    for(int j=i ; a[j]!='\0' ; j++)
    {
        swap(a[i],a[j]);
        permute(a,i+1);
        //this is backtracking when we try to undo changes done in the previous recursive calls
        swap(a[i],a[j]);
    }

}
int main() {
    char name[]= "abc";
    permute(name,0);
}
