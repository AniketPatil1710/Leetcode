#define P pair<int,pair<int,int>>
class Solution {
private : 
    vector<int> dx = {-1,0,+1,0} ;
    vector<int> dy = {0,-1,0,+1} ;

    bool check(int r,int c , int n , int m)
    {
        return (r>=0 && r<n && c>=0 && c<m) ;
    }
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int n = h.size() ;
        int m = h[0].size() ;

        vector<vector<int>> diff(n,vector<int>(m,1e9)) ;

        priority_queue<P,vector<P>,greater<P>> pq ;

        diff[0][0] = 0 ;

        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            auto it = pq.top() ;
            int d = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;
            
            if(x==n-1 && y==m-1)
            {
                return d ;
            }
            pq.pop();

            for(int i=0 ; i<4; ++i)
            {
                int n_x = x+dx[i] ;
                int n_y = y+dy[i] ;


                if(check(n_x,n_y,n,m))
                {
                    int n_d = abs(h[x][y]-h[n_x][n_y]);
                    if(max(d,n_d)<diff[n_x][n_y])
                    {
                        diff[n_x][n_y] = max(d,n_d) ;
                        pq.push({diff[n_x][n_y],{n_x,n_y}});
                    }
                }
            }
        }
        return -1 ;
    }
};