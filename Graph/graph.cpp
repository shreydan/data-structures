#include <iostream>
using namespace std;

class Graph {
    // implementation of undirected weighted graph

   private:
    struct vertex {
        int value;
    };

   public:
    int vertices;
    // adjacency matrix where
    // edge exists: [start][end] = [end][start] = weight
    // edge doesn't exists: weight = 0
    vertex *vertexList;
    int **adjMatrix;
    int length;

    void addVertex(int value) {
        if (length == vertices) {
            cout << "overflow\n";
        } else {
            vertexList[length].value = value;
            length++;
        }
    }

    void addEdge(int startVertex, int endVertex, int weight) {
        // indexing starts with 0
        if (adjMatrix[startVertex][endVertex] == 0 &&
            adjMatrix[endVertex][startVertex] == 0) {
            adjMatrix[startVertex][endVertex] = weight;
            adjMatrix[endVertex][startVertex] = weight;
        } else {
            cout << "edge already exists\n";
        }
    }

    void display() {
        cout << "vertices:" << endl;
        for (int i = 0; i < length; i++) {
            cout << vertexList[i].value << " ";
        }
        cout << "\nadjacency matrix:" << endl;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Graph(int vertices) {
        this->vertices = vertices;
        length = 0;
        vertexList = new vertex[this->vertices];
        *adjMatrix = new int[this->vertices];
        for (int i = 0; i < this->vertices; i++) {
            adjMatrix[i] = new int[this->vertices];
        }
        for (int row = 0; row < vertices; row++) {
            for (int col = 0; col < vertices; col++) {
                adjMatrix[row][col] = 0;
            }
        }
    }

    ~Graph() {
        delete[] vertexList;
        for (int row = 0; row < vertices; row++) {
            delete[] adjMatrix[row];
        }
        // delete[] adjMatrix; -- not working idk why
    }
};

int main() {
    Graph g(4);
    g.addVertex(20);
    g.addVertex(30);
    g.addEdge(0, 1, 100);
    g.display();
}