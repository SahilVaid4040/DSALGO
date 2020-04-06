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
    //check for undirectedGraph
    bool isCyclic_BFS(t src)
    {
        unordered_map<t,bool>visited;
        unordered_map<t,t>parent;
        queue<t>q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while(!q.empty())
        {
            t node  = q.front();
            q.pop();
            for(auto neighbour:adjList[node])
            {
                if(visited[neighbour] && parent[node]!=neighbour)
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }    
        }
        return false;
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
};
int main() {
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,1);
    g.print();
    cout<<g.isCyclic_BFS(1);
    return 0;
}

