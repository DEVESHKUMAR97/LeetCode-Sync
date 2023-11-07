class MaximumArea {
  int n;
  int m;
  vector<vector<bool>> vis;
  vector<vector<int>> grid;
  
  vector<vector<pair<int, int>>> parent;
  map<pair<int, int>, int> sizeOfComponent; 
  vector<int> dirRow {1, -1, 0, 0};
  vector<int> dirCol {0, 0, 1, -1};
  
/*  
  pair<int, int> find(pair<int, int> u) {
   if(parent[u.first][u.second] == u) return u;
    
    return parent[u.first][u.second] = find(parent[u.first][u.second]); // path compres
    
  }
  */
  
  int dfs(int uRow, int uCol, int rowParent, int colParent) {
    int size = 1;
    vis[uRow][uCol] = true;
    parent[uRow][uCol] = {rowParent, colParent};
    
    for(int i = 0; i < 4; i++) {
      int vRow = uRow + dirRow[i];
      int vCol = uCol + dirCol[i];
      if(0 <= vRow && vRow < n && vCol >= 0 && vCol < m && grid[vRow][vCol] == 1 && vis[vRow][vCol] == false) {
        size += dfs(vRow, vCol, rowParent, colParent); 
      }
    }
    return size;
  }
  
  public:
  
    int maximumArea(vector<vector<int>>& grid) {
      
      this->grid = grid;
    
    n = grid.size();
    m = grid[0].size();
      
      
    parent = vector<vector<pair<int, int>> > (n, vector<pair<int, int>> (m));
    
    vis = vector<vector<bool>>(n, vector<bool> (m, false));
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(vis[i][j] == false && grid[i][j] == 1) {
          int size = dfs(i, j, i, j);
          sizeOfComponent[make_pair(i, j)] = size;
          ans = max(ans, size);
        }
      }
    }
      
      
      
      int currAns = 0;
     
      for(int i = 0; i < n; i++) {
        
       for(int j = 0; j < m; j++) {
          if(grid[i][j] == 0) {
            currAns = 1;
            set<pair<int, int>> usedSet;
            for(int k = 0; k < 4; k++) {
              int vRow = i + dirRow[k];
              int vCol = j + dirCol[k];
              if(0 <= vRow && vRow < n && vCol >= 0 && vCol < m && grid[vRow][vCol] != 0) {
                if(!usedSet.count(parent[vRow][vCol])) {
                 currAns +=  sizeOfComponent[parent[vRow][vCol]];
                  usedSet.insert(parent[vRow][vCol]);
                }
                
              }
              
            }
            ans = max(ans, currAns);
          }
       }
      }
      
     return ans;
  }
  
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        MaximumArea m;
        return m.maximumArea(grid);
    }
};