class UnionFind {
    int n;
    vector<int> parent;
    vector<int> rankk;
    public:
    UnionFind(int n) {
        this-> n = n;
        parent = vector<int> (n, -1);
        rankk = vector<int> (n, 1);
    }
    
    int find(int u) {
        if(parent[u] < 0) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        
        if(rankk[u] <= rankk[v]) {
            // make v parent
            parent[u] = v;
            if(rankk[u] == rankk[v]) rankk[v]++;
        } else {
            parent[v] = u;
        }
        return true;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int h = 1;
        for(int w: wells) {
            pipes.push_back({0, h, w});
            h++;
        }
        
        sort(pipes.begin(), pipes.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        UnionFind uFind(n+1);
        
        int ans = 0;
        for(vector<int>& pipe: pipes) {
            if(uFind.merge(pipe[0], pipe[1])) ans += pipe[2];
        }
        return ans;
        
        
        
    }
};