class UnionFind {
    int n;
    vector<int> parent;
    public:

    UnionFind(int n) {
        this->n = n;
        parent = vector<int> (n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void setParent(int u, int par) {
        parent[u] = par;
    }
};
class Solution {
public:
    // O(n * log(n)) because now, from each u, we will only check unvisited v using find 
    // at each time, unvisited nodes decreased by 2
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        // vector<bool> vis(n, false); // no need of visited now
        vector<int> ans(n, -1);

        UnionFind ufind(n+2);


        for(int i = 0; i < banned.size(); i++) {
            ufind.setParent(banned[i], banned[i] + 2);
        }
        
        int visCount = banned.size();
        
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        ufind.setParent(p, p + 2);
        visCount++;
        
        for(int level = 0; q.size() > 0; level++) {
            for(int m = q.size(); m > 0; m--) {
                int u = q.front();
                q.pop();

                int left = u - (k - 1);
                if(left < 0) {
                    int temp = abs(left);
                    left += 2 * temp;
                }

                int right = u + (k - 1);
                if(right >= n) {
                    int temp = abs(right - (n-1));
                    right -= 2 * temp;
                }

                for(int v = ufind.find(left); v <= right; v = ufind.find(v)) {
                    ans[v] = level + 1;
                    q.push(v);
                    visCount++;
                    ufind.setParent(v, ufind.find(v + 2));
                    if(visCount == n) return ans;
                }

            }
        }
        return ans;
    }
};