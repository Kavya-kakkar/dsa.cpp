#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int u , int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }
     void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0); //source node
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();

            cout<< u << " ";

            for(int v : l[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void dfsHelper(int u , vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]) {
            if(!vis[v]) {
                dfsHelper(v , vis);
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<bool> vis(V, false);

        dfsHelper(src , vis);
        cout << endl;

    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    
    cout << "dfs : ";
    g.dfs();
    cout << "bfs : ";
    g.bfs();

    return 0;
}