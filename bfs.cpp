#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Graph {
public:
    int size;
    bool* visited;
    int* bfs_traversed;

    Graph(int n) {
        size = n;
        visited = new bool[size]{false};
        bfs_traversed = new int[size]{0};
    }

    Node* createNode(int element);
    void addEdge(Node* adjList[], int u, int v);
    void BFS(Node* adjList[], int startvertex);
    void display();
};

Node* Graph::createNode(int element) {
    Node* newNode = new Node();
    newNode->data = element;
    newNode->next = nullptr;
    return newNode;
}

void Graph::addEdge(Node* adjList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void Graph::BFS(Node* adjList[], int startvertex) {
    queue<int> q;
    visited[startvertex] = true;
    q.push(startvertex);
    int i = 0;
    while (!q.empty()) {
        int item = q.front();
        cout<<item<<endl;
        bfs_traversed[i++] = item;
        q.pop();
        Node* neighbours = adjList[item];
        while (neighbours != nullptr) {
            int adjacent = neighbours->data;
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
            }
            neighbours = neighbours->next;
        }
    }
}

void Graph::display() {
    for (int i = 0; i < size; i++) {
        if (bfs_traversed[i] != 0)
            cout << bfs_traversed[i] << endl;
    }
}

int main() {
    Graph g1(10);
    Node* adjList[10] = {nullptr};
    g1.addEdge(adjList, 1, 2);
    g1.addEdge(adjList, 1, 3);
    g1.addEdge(adjList, 2, 3);
    g1.addEdge(adjList, 2, 4);
    g1.addEdge(adjList, 2, 5);
    g1.addEdge(adjList, 3, 5);
    g1.addEdge(adjList, 5, 6);
    g1.addEdge(adjList, 4, 5);
    g1.addEdge(adjList, 3, 7);
    g1.addEdge(adjList, 3, 8);
    g1.BFS(adjList, 1);
    // g1.display();

    return 0;
}
