class Solution{

private :
    bool check(int n,int m , int row,int col)
    {
        if((row>=0 && row<n)&&(col>=0 && col<m))
        {
            return true ;
        }
        return false ;
    }

    int bfs(int n , int m , vector<vector<int>> &grid , queue<pair<pair<int,int>,int>> &q , vector<vector<int>> &vis)
    {
        int t = 0 ;

        vector<int> dx = {0,-1,0,+1} ;
        vector<int> dy = {-1,0,+1,0} ;

        while(!q.empty())
        {
            int r = q.front().first.first ;
            int c = q.front().first.second;
            int in_t = q.front().second ;
            
            t = max(t,in_t) ;

            q.pop() ;

            for(int k=0 ; k<4 ; ++k)
            {
                int row = r + dx[k] ;
                int col = c + dy[k] ;
                
                if(check(n,m,row,col) && vis[row][col]==0 && grid[row][col]==1)
                {
                    
                    q.push({{row,col},in_t+1});
                    vis[row][col] = 1 ;
                }
            }
        }

        for(int i=0 ; i<n ; ++i)
        {
            for(int j=0 ; j<m ; ++j)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    return -1 ;
                }
            }
        }
        return t ;
    }

public:
    int orangesRotting(vector<vector<int>> &grid) {
       
       int n = grid.size() ;
       int m = grid[0].size() ;

       vector<vector<int>> vis(n,vector<int>(m,0)) ;

       queue<pair<pair<int,int>,int>> q ;

       for(int i=0 ; i<n ; ++i)
       {
            for(int j=0 ; j<m ; ++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0}) ;
                    vis[i][j] = 2 ;
                }
            }
       }

       int time = bfs(n,m,grid,q,vis) ;

       return time ;
       
    }
};