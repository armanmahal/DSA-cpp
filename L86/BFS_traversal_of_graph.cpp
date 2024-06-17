// BFS - Breadth First Search traversal of graph.
// APPROACH: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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

// BFS traversal
void bfs(unordered_map<int, list<int>> adj, vector<bool> &visited, int vertices, int startNode)
{
    // create a queue:
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // iterate over the queue:
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // get all the adjacent vertices of the currentNode and if it is not marked as visited than enqueue it:
        for (auto i : adj[currentNode])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

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

    // bfs traversal:
    int vertices = 5;
    int startNode = 0;
    // getting the adjacency list of the graph g:
    unordered_map<int, list<int>> adj = g.adj;

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    bfs(adj, visited, vertices, startNode);
    cout << endl;
}