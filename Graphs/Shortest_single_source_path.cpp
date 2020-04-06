#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
#include <stack>
using namespace std;
template<typename t>
class Graph
{
    unordered_map<t,list<t>> adjList;
    public:
    Graph()
    {

    }
    void addEdge(t u, t v, bool bi_dir = true)
    {
        adjList[u].push_back(v);
        if(bi_dir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        //iterate over map
        for(auto obj: adjList)
        {
            cout<<obj.first<<"-> ";
            //obj.second() is  ll;
            for(auto entry:obj.second)
            {
                cout<<entry<<" ";
            }
            cout<<"\n";
        }
    }
    void BFS(t src,t des)
    {
        //unordered_map<t, bool>visited;
        queue<t>q;
        unordered_map<t,int>dist;
        unordered_map<t,t>parent;
        for(auto i:adjList)
        {   
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        //visited[src] = true;
        dist[src]  =0;
        parent[src] = src;
        while(!q.empty())
        {
           t a = q.front();
            //cout<<a<<" ";
            q.pop();
            for(auto x:adjList[a])
            {   if(dist[x]==INT_MAX)
                {
                q.push(x);
                //visited[x] = true;
                dist[x] = dist[a]+1;
                parent[x] = a;
                }
            }
        }
        //cout<<endl;
        //printing the distance to all the nodes
        cout<<"Shortest Distance between "<<src<<" and "<<des<<" is "<<dist[des];
        cout<<"\nAnd the shorrtest path is ";
        t x  = des;
        stack<t>s;
        while(x!=src)
        {
            s.push(x);
            x = parent[x];
        }
        cout<<src<<" -> ";
        while(!s.empty())
        {
            cout<<s.top()<<" -> ";
            s.pop();
        }

    }
};
int main() { 
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.print();
    g.BFS(0,5);
    return 0;
}
