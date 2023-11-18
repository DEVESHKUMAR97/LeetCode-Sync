class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        vector<int> dirRow {1, -1, 0, 0};
        vector<int> dirCol {0, 0, 1, -1};
        
        function<int(int, int)> dfs = [&](int uRow, int uCol) {
            if(uRow < 0 || uCol < 0 || uRow >= n || uCol >= m || grid[uRow][uCol] == 0) return 1;
            if(vis[uRow][uCol]) {
                return 0;
            }
            vis[uRow][uCol] = true;
            int ans = 0;
            
            ans += dfs(uRow + 1, uCol);
            ans += dfs(uRow - 1, uCol);
            ans += dfs(uRow, uCol + 1);
            ans += dfs(uRow, uCol - 1);
            return ans;
        };
        bool flag = false;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    flag = true;
                    ans = dfs(i, j);
                    break;
                }
            }
            if(flag == true) break;
        }
        if(flag == false) return 0;
        return ans;
    }
};