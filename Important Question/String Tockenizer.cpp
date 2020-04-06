#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char s[] = "Hi, My name is Sahil Vaid";
    //tokenizes around both space and comma
    char *ptr = strtok(s," ,");
    while(ptr!=NULL)
    {
        cout<<ptr<<" ";
        //NULL as a parameter signifies to extract from the original string
        //this contains a static variable that stores string in the previous call
        ptr = strtok(NULL," ,");
    }
    return 0;
}
