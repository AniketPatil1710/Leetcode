class Solution {

private: 

bool check(int n , int m , int row , int col)
{
    if((row>=0 && row<n)&&(col>=0 && col<m))
    {
        return true ;
    }
    return false ;
}

void dfs(int i, int j , vector<vector<int>> &grid , vector<vector<bool>> &vis ,int &area)
{

    vis[i][j] = true ;
    ++area ;

    int n = grid.size();
    int m = grid[0].size() ;

    int dx[] = {-1, 0, 1, 0} ;
    int dy[] =  {0, 1, 0, -1} ;

    for(int k=0 ; k<4 ; ++k)
    {
        int row = i + dx[k] ;
        int col = j + dy[k] ;

        
    
        if(check(n,m,row,col) && !vis[row][col] && grid[row][col] == 1)
        {
            dfs(row,col,grid,vis,area);
        }
        
    }

}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {   

        int n = grid.size() ;
        int m = grid[0].size() ;
        int area = 0 ;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int p_max = 0 ;

        for(int i = 0 ; i<n ; ++i)
        {
            for(int j=0 ; j<m ; ++j)
            {
                if(grid[i][j]==1)
                {
                    area = 0 ;
                    dfs(i,j,grid,vis,area);
                    p_max = max(p_max,area);
                   
                }
            }
        }
        return p_max ;
        
    }
};