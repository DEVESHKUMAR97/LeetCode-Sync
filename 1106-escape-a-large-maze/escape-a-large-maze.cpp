class Solution {
    int maxLevels;
    int bfs(unordered_map<int, unordered_set<int>>& blockedSet, vector<int>& source, vector<int>& target) {
        int n, m;
        n = m = 1e6;

        vector<vector<int> > directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<vector<int>> q;
        q.push(source);
        unordered_map<int, unordered_set<int>> vis;
        vis[source[0]].insert(source[1]);

        int level;
        for(level = 0; level <= maxLevels && q.size() > 0; level++) {
            for(int k = q.size(); k > 0; k--) {
                vector<int> u = q.front(); q.pop();
                if(u == target) {
                    return -2; // code that we have found target;
                }
                for(int i = 0; i < 4; i++) {
                    int vRow = u[0] + directions[i][0];
                    int vCol = u[1] + directions[i][1];
                    vector<int> v {vRow, vCol};
                    if(vRow >= 0 && vRow < n && vCol >= 0 && vCol < m && (!blockedSet.count(vRow) || !blockedSet[vRow].count(vCol)) && (!vis.count(vRow) || !vis[vRow].count(vCol))) {
                        q.push(v);
                        vis[vRow].insert(vCol);
                    }
                }
            }
        }
        if(level < maxLevels) {
            // trapped in a cycle
            return -1; // code that source is trapped in cycle
        }

        return maxLevels; // code that source cannot be trapped in cycle

    }
public:
    // time: O(b^2) and space O(b^2)
    // b = blocked.size()
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        maxLevels = blocked.size();

        unordered_map<int, unordered_set<int>> blockedSet;
        for(vector<int>& b: blocked) {
            blockedSet[b[0]].insert(b[1]);
        }

        int ans1 = bfs(blockedSet, source, target);
        cout << ans1 << endl;
        if(ans1 == -2) return true; // reached to target while running bfs
        if(ans1 == -1) return false; // source trapped in cycle

        // now, gauranteed source is not trapped in cycle

        // running bfs again to check if target is trapped in cycle
        int ans2 = bfs(blockedSet, target, source);
        if(ans2 == -1) return false; // target is trapped in cycle

        return true; // both target and source are not trapped in cycle. So, there must exist a path

        
    }
};