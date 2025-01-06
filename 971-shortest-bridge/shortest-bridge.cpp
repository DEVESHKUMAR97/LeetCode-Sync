vector<int> dx={1, -1, 0, 0};
vector<int> dy={0, 0, 1, -1};
// megha's code
void bfs_cmp(vector<vector<int>> &a, int sx, int sy, vector<vector<int>> &vis)
{
    int n=a.size();
    int m=a[0].size();
    queue<int> qx;
    queue<int> qy;
    qx.push(sx);
    qy.push(sy);
    vis[sx][sy]=1;

    while(qx.size()>0)
    {
        int ux=qx.front();
        int uy=qy.front();
        qx.pop();
        qy.pop();
         
        for(int i=0;i<4;i++)
        {
            int vx=ux+dx[i];
            int vy=uy+dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m && vis[vx][vy]==0 && a[vx][vy]==1)
            {
                vis[vx][vy]=1;
                qx.push(vx);
                qy.push(vy);

            }
        }

       
    }

}


int bfs(vector<vector<int>> &a, vector<vector<int>> &ovis, queue<int> &qx, queue<int> &qy)
{
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis=ovis;

    int nicl=qx.size();
    int ninl=0;
    int level=0;
    int ux;
    int uy;

    while(qx.size()>0)
    {
        ux=qx.front();
        uy=qy.front();
        nicl--;
        qx.pop();
        qy.pop();

        if (ovis[ux][uy]==0 && a[ux][uy]==1)
            return level-1;
        

        for(int i=0;i<4;i++)
        {
            int vx=ux+dx[i];
            int vy=uy+dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m && vis[vx][vy]==0)
            {
                vis[vx][vy]=1;
                qx.push(vx);
                qy.push(vy);
                ninl++;

            }
        }

        if(nicl==0)
        {
            nicl=ninl;
            ninl=0;
            level++;
        }

    }       

    return -1;
}





class Solution {
public:
    int shortestBridge(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    bfs_cmp(a, i, j, vis);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        queue<int> qx;
        queue<int> qy;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                {
                    qx.push(i);
                    qy.push(j);

                }
                
            }
        }


        int ans=bfs(a, vis, qx, qy);
        return ans;
    }
};