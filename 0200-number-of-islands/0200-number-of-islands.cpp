class Solution{

private :

    bool check(int row,int col,int n,int m)
    {
        if((row>=0 && row<n)&&(col>=0 && col<m))
        {
            return true ;
        }
        return false ;
    }

    void dfs(int i,int j , vector<vector<bool>> &vis , vector<vector<char>> &grid)
    {
        vis[i][j] = true ;
        int n = grid.size() ;
        int m = grid[0].size() ;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};


        for(int k = 0 ; k<4 ; ++k)
        {
            int row = i + dx[k] ;
            int col = j + dy[k] ;

            if (check(row, col, n, m) && !vis[row][col] && grid[row][col] == '1') {
                dfs(row, col, vis, grid);
            }

        }


    }

public:

    int numIslands(vector<vector<char>> &grid){

        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<bool>> vis(n,vector<bool>(m,false)) ;

        int num_Islands = 0 ;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==false)
                {
                    dfs(i,j,vis,grid);
                    ++num_Islands ;
                }
            }
        }
        return num_Islands;
    }
};

