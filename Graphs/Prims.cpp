#include <iostream>
#include <list>
#define inf 1e9
using namespace std;
class Graph{
    public:
    int V;
    list<pair<int,int>>*adjList;
    Graph(int v){
        V = v;
        adjList  = new list<pair<int,int>>[V];
    }
    void addEdge(int u,int v,int w)
    {
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    int getmin(bool* visited, int* weight){
        int mini = -1;
        for(int i=0; i<V; i++){
            if(!visited[i] && (weight[i]<weight[mini] || mini==-1))
            {
                mini  = i;
            }
        }
        return mini;
    }
    void Prims(){
        bool* visited = new bool[V];
        int* parent = new int[V];
        int* weight = new int[V];
        for(int i=0; i<V; i++){
            visited[i] = false;
            weight[i] = inf;
        }
        weight[0] = 0;
        parent[0] = -1;
        for(int i=0; i<V; i++)
        {
            int min_vertex  = getmin(visited,weight);
            visited[min_vertex] = true;
            for(auto x:adjList[min_vertex])
            {
                if(!visited[x.first])
                {
                    if(weight[x.first]>x.second)
                    {
                        parent[x.first] = min_vertex;
                        weight[x.first] = x.second;
                    }
                }
            }
        }
    
    int dis =0;
    for(int i =1; i<V; i++)
    {
        dis+=weight[i];
    }
    cout<<dis;
    }
};
int main() {
    int n,e;
    cin>>n>>e;
    Graph g(n);
    for(int i=0; i<e; i++)
    {   int s,d,w;
        cin>>s>>d>>w;
        g.addEdge(s,d,w);
    }
    g.Prims();
    return 0;
}

