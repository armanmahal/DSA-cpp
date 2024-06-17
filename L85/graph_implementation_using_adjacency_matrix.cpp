// implementation of class for graph data structure using matrix.

#include <iostream>
#include <vector>
using namespace std;

// directed graph:
class Graph
{
private:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency matrix (can be bool or int for weighted)

public:
    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        // Initialize adjacency matrix with all values initially set to 0
        for (int i = 0; i < V; i++)
        {
            vector<int> row;
            for (int j = 0; j < V; j++)
            {
                row.push_back(0);
            }
            adj.push_back(row);
        }
    }

    // Function to add an edge from vertex u to vertex v
    void addEdge(int u, int v, int weight = 1)
    {
        adj[u][v] = weight;
        // If the graph is undirected, add the following line:
        // adj[v][u] = weight;
    }

    // Function to print the adjacency matrix
    void printGraph()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph g(3);

    // Add some edges
    g.addEdge(0, 1, 3); // Edge from vertex 0 to vertex 1 with weight 3
    g.addEdge(0, 2, 2); // Edge from vertex 0 to vertex 2 with weight 2
    g.addEdge(2, 1, 1); // Edge from vertex 2 to vertex 1 with weight 1

    // Print the adjacency matrix
    g.printGraph();

    return 0;
}
