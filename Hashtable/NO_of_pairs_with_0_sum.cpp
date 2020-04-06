#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int,int>myMap;
    myMap[1] = 2;
    myMap[-1]  = 3;
    myMap[2] = 5;
    myMap[3] = 4;
    myMap[-3] = 10;
    int ans =0;
    int j;
    int k;
    int l;
    for(int i=0 ; i<myMap.bucket_count(); i++)
    {
        for(auto it = myMap.begin(i); it!=myMap.end(i);it++)
        {
        j = it->first;
        l = it->second;
        if(j>0)
        {
          k  = myMap[-j];
          ans +=k*l;
        }
       }
    }
    cout<<ans;
    return 0;
}
