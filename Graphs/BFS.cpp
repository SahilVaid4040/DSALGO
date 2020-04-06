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
};
int main() {
    Graph<string> g;
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump");
    g.addEdge("Prabhu","Modi",false);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Yogi","Modi");
    g.print();
    g.BFS("Modi");
    return 0;
}
