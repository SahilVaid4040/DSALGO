#include <iostream>
#include <map>
#include <list>
#include <cstring>
using namespace std;
template <typename t>
class Graph
{
    map<t,list<t>>adjList;
    public:
    void AddEdge(t u, t v, bool birDir = true)
    {
        adjList[u].push_back(v);
        if(birDir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(t src,map<t,bool>&visited)
    {
        visited[src] = true;
        cout<<src<<" ";
        for(t neighbour:adjList[src])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }
    void DFS(t src)
    {
        map<t,bool>visited;
        int component = 1;
        dfsHelper(src,visited);
        cout<<endl;
        for(auto i:  adjList)
        {
            t city = i.first;
            if(!visited[city])
            {
                dfsHelper(city,visited);
                cout<<"\n";
                component++;
            }
        }
        cout<<"The Graph has "<<component<<" components\n";
    }
    void DFS_Topological_Sort_Helper(t node,map<t,bool>&visited,list<t>&ordering)
    {
        visited[node] = true;
        for(t x: adjList[node])
        {
            if(!visited[x])
            {
                DFS_Topological_Sort_Helper(x,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void DFS_Topological_Sort()
    {   map<t,bool>visited;
        list<t>ordering;
        for(auto i: adjList)
        {
            if(!visited[i.first])
            {
                DFS_Topological_Sort_Helper(i.first,visited,ordering);
            }
        }
        for(t x:ordering)
        {
            cout<<x<<" ";
        }
    }
};
int main() {
    Graph<string>g;
    g.AddEdge("English","Programming Logic",false);
    g.AddEdge("English","HTML",false);
    g.AddEdge("Programming Logic","HTML",false);
    g.AddEdge("Maths","Programming Logic",false);
    g.AddEdge("Programming Logic","Python",false);
    g.AddEdge("Programming Logic","Java",false);
    g.AddEdge("HTML","CSS",false);
    g.AddEdge("CSS","JS",false);
    g.AddEdge("Programming Logic","JS",false);
    g.AddEdge("Python","Web Dev",false);
    g.AddEdge("Java","Web Dev",false);
    g.AddEdge("JS","Web Dev",false);
    g.DFS_Topological_Sort();
    return 0;
}

