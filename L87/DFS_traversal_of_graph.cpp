// DFS - Depth First Search traversal of graph.
// APPROACH: hhttps://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
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

// DFS traversal
void dfs(unordered_map<int, list<int>> adj, vector<bool> &visited, int vertices, int startNode)
{
    // create a vector:
    vector<int> v;
    // Mark the current node as visited and add it to vector
    visited[startNode] = true;
    v.push_back(startNode);

    // iterate over the vector:
    while (!v.empty())
    {
        int currentNode = v.back();
        v.pop_back();
        cout << currentNode << " ";

        // get all the adjacent vertices of the currentNode and if it is not marked as visited than add it to vector:
        for (auto i : adj[currentNode])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                v.push_back(i);
            }
        }
    }
}

int main()
{
    Graph g;

    g.addEdge(0, 1, false); // Edge from vertex 0 to vertex 1 (undirected).
    g.addEdge(0, 2, false); // Edge from vertex 1 to vertex 2 (undirected).
    g.addEdge(0, 3, false); // Edge from vertex 2 to vertex 2 (undirected).
    g.addEdge(2, 3, false); // Edge from vertex 1 to vertex 3 (undirected).
    g.addEdge(2, 4, false); // Edge from vertex 3 to vertex 4 (undirected).

    g.printAdjList();

    // bfs traversal:
    int vertices = 5;
    int startNode = 0;
    // getting the adjacency list of the graph g:
    unordered_map<int, list<int>> adj = g.adj;

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    dfs(adj, visited, vertices, startNode);
    cout << endl;
}