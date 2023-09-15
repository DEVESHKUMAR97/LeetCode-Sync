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
    // void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     auto p1=lower_bound(intervals.begin(),intervals.end(),newInterval[0],[](const auto& x, int v){ return x[1]<v; });
    //     auto p2=upper_bound(intervals.begin(),intervals.end(),newInterval[1],[](int v, const auto& x){ return v<x[0]; });
    //     vector<int>& x=newInterval;
    //     if (p1!=p2) {
    //         x[0]=min((*p1)[0],x[0]);
    //         x[1]=max((*prev(p2))[1],x[1]);
    //     }
    //     intervals.erase(p1,p2);
    //     intervals.insert(p1,x);
    // }
    // vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
    //     vector<int> res(n,-1);
    //     for (int b : banned) res[b]=INT_MAX;
    //     queue<int> q;
    //     q.push(p);
    //     int d=0;
    //     res[p]=d;
    //     while (not q.empty()) {
    //         ++d;
    //         vector<vector<int>> intervals;
    //         for (int i=0, m=int(q.size()); i<m; ++i) {
    //             int x=q.front(); q.pop();
    //             // y1+2*z>=0, z>=(1-y1)/2
    //             // y1+z>=0, z>=-y1
    //             int y1=x-k+1;
    //             if (y1<0) y1+=max(((1-y1)/2),-y1)*2;
    //             // y2-2*z<n, z>=(y2-n)/2+1
    //             // y2-z<n, z>=(y2-n)+1
    //             int y2=x+k-1;
    //             if (y2>=n) y2-=max((y2-n)/2,y2-n)*2+2;
    //             vector<int> r{y1,y2+2};
    //             insert(intervals,r);
    //         }
    //         for (auto& r : intervals) {
    //             for (int y=r[0]; y<r[1]; y+=2) {
    //                 if (res[y]==-1) {
    //                     res[y]=d;
    //                     q.push(y);
    //                 }
    //             }
    //         }
    //     }
    //     for (int i=0; i<n; ++i)
    //         if (res[i]==INT_MAX) res[i]=-1;
    //     return res;
    // }

    // Approach 1: using dsu to traverse on range
    // O(n * log(n)) because now, from each u, we will only check unvisited v using find 
    // at each time, unvisited nodes decreased by 2 atmost
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
        ufind.setParent(p, ufind.find(p + 2));
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