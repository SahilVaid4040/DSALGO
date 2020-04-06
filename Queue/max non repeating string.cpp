#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char a[] = "abcefbca";
    int n = strlen(a);
    int visited[256];
    for(int i=0 ;i<256; i++)
    visited[i] = -1;
    visited[a[0]] = 0;
    int max_len=1;
    int current_len =1;
    int last_occ=-1;
    for(int i=1 ; i<n ;i++)
    {
    last_occ  = visited[a[i]];
    //expansion
    if(last_occ==-1 || last_occ<(i-current_len))
    current_len++;
    //expansion and contraction case
    else
    current_len = i-last_occ;
    max_len = max(current_len,max_len);
    visited[a[i]] = i;
    }
    cout<<max_len;
    return 0;
}
