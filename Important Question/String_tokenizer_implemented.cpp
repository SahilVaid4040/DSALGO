#include <iostream>
#include <cstring>
using namespace std;
char *mystrtok(char str[],char deliminator)
{
    static char *input = NULL;
    if(str!=NULL)
    {
        input = str;
    }
    if(input==NULL)
    {
        return  NULL;
    }
    char *OUTPUT = new char[strlen(input)+1];
    //+1 for the /0 after the string
    int i;
    for(i=0; input[i]!='\0';i++)
    {
        if(input[i]!=deliminator)
        {
            OUTPUT[i] = input[i];
        }
        else
        {
            OUTPUT[i] = '\0';
            input = input+i+1;
            return OUTPUT;
        }
    }
    OUTPUT[i] = '\0';
    input = NULL;
    return OUTPUT;
}
int main() {
    char truth[] = "My name is sahil vaid";
    char *ptr = mystrtok(truth,' ');
    while(ptr!=NULL)
    {
        cout<<ptr<<" ";
        ptr = mystrtok(NULL,' ');
    }
    return 0;
}
