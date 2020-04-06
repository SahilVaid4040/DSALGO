#include <iostream>
#include <cstring>
using namespace std;
//time complexity -o(n*2^n)
//filterstring converts your number that you had in binary form to the string associated
//like for s =abs and n =1 it will give a  for 2 b and 3 ab
void filterstring(string s,int n)
{   int i = 0;
    while(n>0){
    (n&1)?cout<<s[i]:cout<<"";
    i++;
    n =n>>1;
    }
    cout<<endl;
}
//getsubstring generates a number corresponding to every substring
void getsubstring(string a)
{
    int n = a.size();
    //range is equal to 0->2^n -1
    int range = (1<<n)-1;
    for(int i =0; i<=range; i++)
    {
        filterstring(a,i);
    }
}
int main() {
    string name = "Sahil Vaid";
    getsubstring(name);
}
