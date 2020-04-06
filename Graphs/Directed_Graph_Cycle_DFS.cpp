#include <iostream>
#include <unordered_map>
#include <list>
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
    bool isCyclic_Helper(t node,unordered_map<t,bool>&visited,unordered_map<t,bool>&inStack)
    {  
        //processing the current node
        visited[node] = true;
        inStack[node] = true;
        for(t neighbour:adjList[node])
        {
            // the current neighbour is not visited but it's further branch is leading to a cycle
            if((!visited[neighbour] && isCyclic_Helper(neighbour,visited,inStack)) || inStack[neighbour])
            {
                return true;
            }
            
        }
        inStack[node] = false;
            return false;


    }
    bool isCyclic()
    {
        unordered_map<t,bool>visited;
        unordered_map<t,bool>inStack;
        //Check for cycle in each DFS tree
        for(auto x:adjList)
        {
            t node  = x.first;
            if(!visited[node])
            {
                bool cycle_present= isCyclic_Helper(node,visited,inStack);
                if(cycle_present)
                {
                    return true;
                }
            }
        }
    return false;
    }
};
int main() {
    Graph<int> g;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    cout<<g.isCyclic();
    return 0;
}
