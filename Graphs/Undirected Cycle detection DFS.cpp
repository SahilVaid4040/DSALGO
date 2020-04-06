#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <queue>
using namespace std;
template <typename t>
class Graph
{
    map<t,list<t>>adjList;
    public:
    void AddEdge(t u,t v, bool biDir = true)
    {
        adjList[u].push_back(v);
        if(biDir)
        {
            adjList[v].push_back(u);
        }
    }
    bool isCyclicHelper(t node,map<t,bool>&visited,t parent)
    {
        visited[node] =true;
        for(t neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                bool ans  = isCyclicHelper(neighbour,visited,node);
                if(ans)
                {
                    return true;
                }
            }
            else if(neighbour!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCyclic(t src)
    {
    map<t,bool>visited;
    for(auto i:adjList)
    {
        t node = i.first;
        if(!visited[node])
        {
            bool ans  = isCyclicHelper(node,visited,node);
            if(ans)
            {
                return true;
            }
        }

    }
    return false;
    }
};
int main() {
    Graph<int>g;
    g.AddEdge(1,2);
    g.AddEdge(1,4);
    //g.AddEdge(4,3);
    g.AddEdge(2,3);
    if(g.isCyclic(1))
    {
        cout<<"Is cyclic";
    }
    else
    {
        cout<<"NOT CYCLIC";
    }
    return 0;
}
