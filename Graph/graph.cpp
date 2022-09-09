#include <bits/stdc++.h>
using namespace std;

/*
    Graph:
        directed<bool>: graph is directed or not
        weighted<bool>: graph is weighted or not
        default:
            undirected, unweighted graph
*/

template <class T>
class Graph {
   public:
    bool directed, weighted;
    unordered_map<T, vector<pair<T, int>>> g;

    Graph(bool d = false, bool w = false) {
        directed = d;
        weighted = w;
    }
    void addEdge(T start, T end, int weight = 0) {
        g[start].push_back(make_pair(end, weight));
        if (!directed) {
            g[end].push_back(make_pair(start, weight));
        }
    }

    void print() {
        for (const auto& [vertex, adjList] : g) {
            cout << vertex << " -> ";
            for (const auto& adjVertex : adjList) {
                if (weighted)
                    cout << adjVertex.first << "(" << adjVertex.second << ") ";
                else
                    cout << adjVertex.first << " ";
            }
            cout << endl;
        }
    }

    int numVertices() {
        return g.size();
    }
};

int main() {
    Graph<string> g(false, true);
    /*
        1----2--
        |    |  \
        |    |   5
        |    |  /
        3----4--
    */
    g.addEdge("one", "two", 10);
    g.addEdge("one", "three", 20);
    g.addEdge("two", "four", 30);
    g.addEdge("two", "five", 40);
    g.addEdge("three", "four", 50);
    g.addEdge("four", "five", 60);
    g.print();
    cout << g.numVertices() << endl;

    return 0;
}
