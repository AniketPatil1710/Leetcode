class Solution {
private :
    bool check(int n , int m , int row , int col)
    {
        if((row>=0 && row<n) && (col>=0 && col<m))
        {
            return true ;
        }
        return false ;
    }
    void dfs(int &n , int &m , int i , int j ,vector<vector<int>>& grid ,vector<vector<bool>> &vis,vector<int> &dx,vector<int> &dy ) 
    {
        vis[i][j] = true ;

        for(int k = 0 ; k<4 ; ++k)
        {
            int row = i + dx[k] ;
            int col = j + dy[k] ;

            if(check(n,m,row,col) && vis[row][col]==false && grid[row][col] == 1)
            {
                dfs(n,m,row,col,grid,vis,dx,dy);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<bool>> vis(n, vector<bool> (m,false));
        vector<int> dx = {0,-1,0,+1};
        vector<int> dy = {-1,0,+1,0};

        for(int i=0 ; i<n ; ++i)
        {
            for(int j=0 ; j<m ; ++j)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(vis[i][j]==false && grid[i][j]==1)
                        dfs(n,m,i,j,grid,vis,dx,dy);
                }
            }
        }

        int cnt = 0 ;

        for(int i = 0 ; i<n ; ++i)
        {
            for(int j = 0 ; j<m ; ++j)
            {
                if((grid[i][j]==1) && (vis[i][j]==false))
                {
                    ++cnt ;
                }
            }
        }

        return cnt ;
        
    }
};