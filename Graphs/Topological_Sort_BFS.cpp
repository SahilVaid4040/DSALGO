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
    void DFS_Helper(t src,unordered_map<t,bool>&visited,list<t>&ordering)
    {
        visited[src] = true;
        for(t neighbour:adjList[src])
        {
            if(!visited[neighbour])
            {
                DFS_Helper(neighbour,visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    void DFS_Topological_Sort()
    {
        unordered_map<t,bool>visited;
        list<t>ordering;
        for(auto i:adjList)
        {
            t node = i.first;
            if(!visited[node])
            {
                DFS_Helper(node,visited,ordering);
            }
        }
        for(t element:ordering)
        {
            cout<<element<<" ";
        }
    }
    void BFS_Topological_Sort()
    {
        queue<t>q;
        unordered_map<t,bool>visited;
        unordered_map<t,int>inDegree;
        //Intitalising the indegree and visited
        for(auto i:adjList)
        {
            t node  = i.first;
            visited[node] = false;
            inDegree[node] = 0;
        }
        //Initializing the indegree
        for(auto i: adjList)
        {
            t u = i.first;
            for(t v:adjList[u])
            {
                inDegree[v]++;
            }
        }
        //Adding all the nodes with 0 indegree to queue
        for(auto i: adjList)
        {
            t node = i.first;
            if(inDegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            t node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto neighbour:adjList[node])
            {
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }

    }
};
int main() {
    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","WebDev",false);
    g.addEdge("Java","WebDev",false);
    g.addEdge("JS","WebDev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.BFS_Topological_Sort();
    
    
    return 0;
}
