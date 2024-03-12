#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

struct Edge
{
    string destination;
    int weight;

    Edge(const string &dest, int w)
    {
        destination = dest;
        weight = w;
    }
};

struct Node
{
    string department;
    vector<Edge> edges;

    Node() : department("") {}

    Node(const string &dep) : department(dep) {}
};

class Graph
{
private:
    int numVertices;
    vector<Node> adjacencyList;
    unordered_map<string, int> vertexIndices;

public:
    Graph(const vector<string> &departments) : numVertices(departments.size()), adjacencyList(numVertices)
    {
        for (int i = 0; i < numVertices; i++)
        {
            adjacencyList[i] = Node(departments[i]);
            vertexIndices[departments[i]] = i;
        }
    }

    void add_new_Edge(const string &source, const string &destination, int weight)
    {
        int sourceIndex = vertexIndices[source];
        int destIndex = vertexIndices[destination];

        adjacencyList[sourceIndex].edges.push_back(Edge(destination, weight));
        adjacencyList[destIndex].edges.push_back(Edge(source, weight));
    }

    void Prims_Algorithm()
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);
        vector<bool> inMST(numVertices, false);

        int startVertex = 0;
        pq.push({0, startVertex});
        key[startVertex] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (const Edge &edge : adjacencyList[u].edges)
            {
                int v = vertexIndices[edge.destination];
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Print MST
        cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
        for (int i = 1; i < numVertices; ++i)
        {
            cout << "Edge: " << adjacencyList[parent[i]].department << " - "
                 << adjacencyList[i].department << " Weight: " << key[i] << endl;
        }
    }
};

int main()
{

    vector<string> departments = {"Information Technology", "Computer Science", "Mechanical", "Electronic", "Electrical"};
    Graph Campus(departments);

    Campus.add_new_Edge("Information Technology", "Computer Science", 2);
    Campus.add_new_Edge("Information Technology", "Mechanical", 4);
    Campus.add_new_Edge("Computer Science", "Mechanical", 1);
    Campus.add_new_Edge("Computer Science", "Electronic", 7);
    Campus.add_new_Edge("Mechanical", "Electrical", 3);
    Campus.add_new_Edge("Electronic", "Electrical", 5);

    Campus.Prims_Algorithm();

    return 0;
}