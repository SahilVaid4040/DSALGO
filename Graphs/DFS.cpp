#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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
    void BFS(t src)
    {
        unordered_map<t, bool>visited;
        queue<t>q;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
           t a = q.front();
            cout<<a<<" ";
            q.pop();
            for(auto x:adjList[a])
            {   if(!visited[x])
                {
                q.push(x);
                visited[x] = true;
                }
            }
        }
    }
    void DFS_Helper(t src,unordered_map<t,bool>&visited)
    {
        visited[src] = true;
        cout<<src<<" ";
        for(t neighbour:adjList[src])
        {
            if(!visited[neighbour])
            {
                DFS_Helper(neighbour,visited);
            }
        }
    }
    void DFS(t src)
    {
        unordered_map<t,bool>visited;
        DFS_Helper(src,visited);
    }
};
int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.DFS(0);
    return 0;
}
