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

    bool isCycleUndirDFS(int src , int par , vector<bool> &vis) { //dfs algo timr complexity O(V + E)

        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(isCycleUndirDFS(v , src , vis)) {
                    return true;
                }
            } 
            else if( v != par) {
                return true;
            }
        }

        return false;

    }
    
    bool isCycle() {
        vector<bool> vis(V, false);

        for( int i = 0 ; i < V ; i++)  {
            if(!vis[i]) {
                if(isCycleUndirDFS(i , -1 , vis)) {
                    return true;
                }

            }
        }
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    
    cout << g.isCycle() << endl;

    return 0;
}