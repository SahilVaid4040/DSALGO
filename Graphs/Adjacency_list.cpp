#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int>* l;
public:
    Graph(int v)
    {
        V= v;
        l = new list<int>[v];
    }
    void Add_Edge(int u,int v,bool bi_dir = true)
    {
        l[u].push_back(v);
        if(bi_dir=true)
        {
            l[v].push_back(u);
        }
    }
    void printAdjlist()
    {
        for(int i=0; i<V ; i++)
        {
            cout<<i<<"-> ";
            for(int vertex:l[i])
            {
                cout<<vertex<<" ";
            }
            cout<<"\n";
        }
    }
};
int main() {
    Graph g(5);
    g.Add_Edge(0,1);
    g.Add_Edge(0,4);
    g.Add_Edge(1,2);
    g.Add_Edge(1,3);
    g.Add_Edge(1,4);
    g.Add_Edge(2,3);
    g.Add_Edge(3,4);
    g.printAdjlist();
    return 0;
}
