#include <iostream>
#include <cstring>
using namespace std;
void subsequences(char *inp, char *out,int i, int j)
{
    //base case
    if(inp[i]=='\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    //Recursive case
    //1. include the current character
    out[j]=inp[i];
    subsequences(inp,out,i+1,j+1);
    //2. do no include the current character
    subsequences(inp,out,i+1,j);
}
int main() {
    char inp[] = "abc";
    char out[100];
    subsequences(inp,out,0,0);
    return 0;

}
