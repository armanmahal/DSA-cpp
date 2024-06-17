// implementation of graph using adjacency list:

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    // adding an edge to the graph
    void addEdge(int u /*from vertex*/, int v /*to vertex*/, bool directed /*is directed edge or not*/)
    {
        adj[u].push_back(v);

        if (directed == false)
        {
            adj[v].push_back(u);
        }
    }

    // function to print:
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, false); // Edge from vertex 0 to vertex 1 (undirected).
    g.addEdge(1, 2, false); // Edge from vertex 1 to vertex 2 (undirected).
    g.addEdge(2, 3, false); // Edge from vertex 2 to vertex 2 (undirected).
    g.addEdge(1, 3, false); // Edge from vertex 1 to vertex 3 (undirected).
    g.addEdge(3, 4, false); // Edge from vertex 3 to vertex 4 (undirected).
    g.addEdge(0, 4, false); // Edge from vertex 0 to vertex 4 (undirected).

    g.printAdjList();
}