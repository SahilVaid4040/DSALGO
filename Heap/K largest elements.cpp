#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
void query_point(priority_queue<int,vector<int>,greater<int>> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
int main() {
    int k=3;
    int no;
    priority_queue<int,vector<int>,greater<int>> pq;
    int cs =0;
    while(scanf("%d",&no)!=EOF)
    {
        if(no==-1)
        {
            query_point(pq);
        }
        else if(cs<k)
        {
            pq.push(no);
            cs++;
        }
        else
        {
            if(no>pq.top())
            {
                pq.pop();
                pq.push(no);
            }
        }
    }
    return 0;
}
