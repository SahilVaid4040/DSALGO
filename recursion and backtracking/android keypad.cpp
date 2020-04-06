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
   char keypad [][200] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
   char out[100];
    int no = 321;
    int rev = 0;
    while(no)
    {
        int j = no%10;
        rev*=10;
        rev+=j;
        no/=10;
    }

    while(rev)
    {
        subsequences(keypad[rev%10],out,0,0);
        rev/=10;

    }
    return 0;

}
