class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto& con: connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        vector<int> inTime(n);
        vector<int> lowInTime(n);
        vector<int> vis(n, 0);
        int timer = 0;

        vector<vector<int>> bridges;

        function<void(int, int)> dfs = [&inTime, &timer, &vis, &lowInTime, &adj, &dfs, &bridges](int u, int par) {
            timer++;
            vis[u] = 1;
            inTime[u] = lowInTime[u] = timer;

            for(int v: adj[u]) {
                if(v == par) continue;
                if(vis[v] == 1) {
                    // back edge: u -> v
                    // cannot be a bridge
                    lowInTime[u] = min(lowInTime[u], inTime[v]);
                } else {
                    // forward edge: u -> v
                    // may or may not be a bridge

                    dfs(v, u);

                    // checking for bridge condition
                    if(lowInTime[v] > inTime[u]) {
                        // bridge
                        bridges.push_back({u, v});
                    }
                    lowInTime[u] = min(lowInTime[u], lowInTime[v]);
                }
            }

        };
        dfs(0, -1);
        return bridges;
    }
};