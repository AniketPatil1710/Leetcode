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

void dfs(int i, int j , vector<vector<int>> &grid , vector<vector<bool>> &vis ,int &perimeter)
{

    vis[i][j] = true ;

    int n = grid.size();
    int m = grid[0].size() ;

    int dx[] = {-1, 0, 1, 0} ;
    int dy[] =  {0, 1, 0, -1} ;

    for(int k=0 ; k<4 ; ++k)
    {
        int row = i + dx[k] ;
        int col = j + dy[k] ;

        if (!check(n, m, row, col)) {
                perimeter++;
        }
        else if (grid[row][col] == 0) {
    
            perimeter++;
        }
        else if(grid[i][j]==1 && vis[i][j]==0)
        {
            dfs(row,col,grid,vis,perimeter);
        }
        
    }

}

public:
    int islandPerimeter(vector<vector<int>>& grid) {   

        int n = grid.size() ;
        int m = grid[0].size() ;
        int perimeter = 0 ;

        vector<vector<bool>> vis(n, vector<bool>(m, false));


        for(int i = 0 ; i<n ; ++i)
        {
            for(int j=0 ; j<m ; ++j)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,vis,perimeter);
                    //break ;
                }
            }
        }
        return perimeter ;
        
    }
};