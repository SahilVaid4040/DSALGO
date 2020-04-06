#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
//problem is to cehck wether parathesis are in order in the given string
//or not eg. ((a+b)+c) are in order but not in (a+b)) or (a+b + c))(
bool Balanceed_Paranthesis(char *s)
{
    stack<char>c;
    int n  = strlen(s);
    for(int i=0  ;i<n ; i++)
    {
        if(s[i]=='(')
        c.push('(');
        else if(s[i]==')')
        {
            if(c.empty())
            return false;
            else c.pop();
        }
    }
    if(c.empty())
    return true;
    else
    return false;

}
int main() {
    char *t  = "(a+b)";
    cout<<Balanceed_Paranthesis(t);
}
