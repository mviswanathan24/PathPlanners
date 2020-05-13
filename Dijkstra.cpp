#include<bits/stdc++.h>
using namespace std;
#define INF 900000

class Graph{
    list<pair<int, int>> *adj;
    int V;

public:
    Graph(int V){
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void createEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));      //  Assuming that the cost of traversing in reverse direction from one node to another is the sane
    }

    void minDistance(int s){
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Initializing all distances to be infinity, since we do not know how far each node is.
        vector<int> distance(V, INF);
        // Initializing the distance to the start node as 0.
        pq.push(make_pair(0, s));
        distance[s] = 0;
        while(!pq.empty()){
            // extracting the value of the node, so that it can be used to find the adjacent nodes while iterating.
            int x = pq.top().second;
            pq.pop();
            // i refers to the vertices adjacent to x.
            for(auto i = adj[x].begin(); i != adj[x].end(); i++){
                // y is the node and wt is the weight of the edge from x to y
                int y = (*i).first;
                int wt = (*i).second;
                // If there exists a distance between u and v that is lesser than the distance that has previously been calculated, assign the shorter distance.
                if(distance[y] > distance[x] + wt){
                    distance[y] = distance[x] + wt;
                    pq.push(make_pair(distance[y], y));
                }
            }
        }
        cout << "Distance from source to each node:"<<endl;
        for(int i = 0; i < V; i++)
            cout << "Node " << i << ": " << distance[i] <<endl;
    }

};

int main(){
    int V = 8;
    Graph g(V);
    // sample graph
    g.createEdge(0, 1, 1);
    g.createEdge(1, 2, 1);
    g.createEdge(2, 4, 1);
    g.createEdge(4, 3, 3);
    g.createEdge(3, 2, 1);
    g.createEdge(1, 5, 4);
    g.createEdge(1, 6, 4);
    g.createEdge(5, 6, 5);
    g.createEdge(6, 7, 4);
    g.createEdge(5, 7, 8);

    g.minDistance(0); //0 here is the start node
}