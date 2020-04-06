#include <iostream>
#include <cstring>
using namespace std;
#define INT_MAX 999999
int n=4;
int dist[10][10]={{0,20,42,25},
                  {20,0,30,34},
                  {42,30,0,10},
                  {25,34,10,0}};
int visited_all = (1<<n)-1;
int DP[4][16];
int tsp(int pos,int state){
    if(DP[pos][state]!=-1){
        return DP[pos][state];
    }
    if(state==visited_all)
    {
        return dist[pos][0];
    }
    int res = INT_MAX;
    for(int city=0;city<n; city++){
        if((state&(1<<city))==0){
           res = min(res,dist[pos][city]+tsp(city,(state|(1<<city))));
        }
    }
    DP[pos][state]=res;
    return res;
}
int main() {
    memset(DP,-1,sizeof(DP));
    cout<<tsp(0,1);
    return 0;
}

