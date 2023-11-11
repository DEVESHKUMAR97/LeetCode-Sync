#define pii pair<int, int>
class Graph {
    int n; 
    vector<vector<pii>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj = vector<vector<pii>> (n, vector<pii>());
        
        for(auto& e : edges) {
            addEdge(e);
        }
        
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // brute force, running dijkstras every time
        // since n <= 100 => max Edges <= 10^4
        // dijkstras run in O(Elog(v))
        // 100 calls of dijkstras => 100 * E * log(V) => 100 * 10^4 * log(100) => 10^6 * log(100) =>AC
        
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        
        minHeap.push({0, node1});
        dist[node1] = 0;
        
        while(minHeap.size() > 0) {
            int u = minHeap.top().second; minHeap.pop();
            if(u == node2) return dist[u];
            
            for(auto &vp: adj[u]) {
                int v = vp.first;
                int vWeight = vp.second;
                if(dist[v] > dist[u] + vWeight) {
                    dist[v] = dist[u] + vWeight;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */