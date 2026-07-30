class Solution {
private:
    vector<int> dx = {-1,-1,0,+1,+1,+1,0,-1} ;
    vector<int> dy = {0,-1,-1,-1,0,+1,+1,+1} ;

    bool check(int row , int col , int n , int m )
    {
        return (row>=0 && row<n && col>=0 && col<m) ;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0]==1)
        {
            return -1 ;
        }
        
        int n = grid.size() ;
        int m = grid[0].size() ;

        if(n==1 && m==1)
        {
            return 1 ;
        }

        queue<pair<int,pair<int,int>>> q ;
        vector<vector<int>> dist(n,vector<int> (m,1e8)) ;

        dist[0][0] = 1 ;
        q.push({0,{0,0}}) ;

        while(!q.empty())
        {
            auto it = q.front() ;
            int d = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;

            q.pop() ;

            for(int i=0 ; i<8 ; ++i)
            {
                int n_x = x+dx[i] ;
                int n_y = y+dy[i] ;

                if(check(n_x,n_y,n,m) && grid[n_x][n_y]==0 && d+1 < dist[n_x][n_y])
                {
                    dist[n_x][n_y] = d+1 ;

                    if(n_x == n-1 && n_y==n-1)
                    {
                        return d+2 ;
                    }

                    q.push({d+1,{n_x,n_y}});

                }
            }
        }

        return -1 ;
    }
};