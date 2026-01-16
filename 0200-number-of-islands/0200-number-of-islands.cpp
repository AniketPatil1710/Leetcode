class Solution {
private:
    void bfs(int i , int j , vector<vector<int>> &vis , vector<vector<char>> &grid)
    {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[i][j] = 1 ;
        queue<pair<int,int>> q ;
        q.push({i,j}) ;

        int dx[] = {1,0,0,-1};
        int dy[] = {0,1,-1,0};
        while(!q.empty())
        {
            auto it = q.front() ;
            q.pop();
            int x = it.first ;
            int y = it.second ;

            for(int k=0 ; k<4 ; ++k)
            {
                int dxp = dx[k]+x ;
                int dyp = dy[k]+y ;

                if(dxp>=0 and dyp>=0 and dxp<n and dyp<m and vis[dxp][dyp]==0 and grid[dxp][dyp]=='1')
                {
                    vis[dxp][dyp]=1;
                    q.push({dxp,dyp});
                }
            }
        }    
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
       
       int n = grid.size() ;
       int m = grid[0].size() ;
       int ans = 0 ;

       vector<vector<int>> vis(n,vector<int> (m,0));

       for(int i=0 ; i<n ; ++i)
       {
           for(int j=0 ; j<m ; ++j)
           {
               if(grid[i][j]== '1'  and vis[i][j]==0)
               {
                   bfs(i,j,vis,grid);
                   ans++;
               }
           }
       }
       return ans ;
    }
};