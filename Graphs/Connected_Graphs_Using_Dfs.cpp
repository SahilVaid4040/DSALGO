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
        int component =1;
        cout<<"\n";
        for(auto i:adjList)
        {
            t city = i.first;
            if(!visited[city])
            {
                DFS_Helper(city,visited);
                cout<<"\n";
                component++;
            }
        }
        cout<<"The graph has "<<component<<" components";
    }
};
int main() {
    Graph<string> g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Agra");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Jaipur","Mumbai");
    g.addEdge("Bhopal","Mumbai");
    g.addEdge("Mumbai","Banglore");
    g.addEdge("Andaman","Nicobar");
    g.DFS("Amritsar");
    
    
    return 0;
}
