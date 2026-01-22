class Solution {        
public:  
    bool check(int n , int m , int row , int col)
        {
            if((row>=0 && row<n)&&(col>=0 && col<m))
            {
                return true ;
            }
            return false ;
        }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0)) ;
        vector<vector<int>> dist(n,vector<int> (m,0)) ;
        queue<pair<pair<int,int>,int>> q ;

        for(int i = 0 ; i<n ; ++i)
        {
            for(int j=0 ; j<m ; ++j)
            {
                if(grid[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1 ;
                }
            }
        }

        vector<int> dx = {0,-1,0,+1} ;
        vector<int> dy = {-1,0,+1,0} ;

        while(!q.empty())
        {
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int steps = q.front().second ;
            q.pop() ;
            dist[r][c] = steps ;

            for(int i=0 ; i<4 ; ++i)
            {
                int row = r + dx[i] ;
                int col = c + dy[i] ;
            

                if(check(n,m,row,col) && vis[row][col]==0)
                {
                    vis[row][col] = 1 ;
                    q.push({{row,col},steps+1}) ;
                }
            }
        }
        return dist ;
    }
};