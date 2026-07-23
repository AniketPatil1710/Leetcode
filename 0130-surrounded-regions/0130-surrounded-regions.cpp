
class Solution{
private:
    bool check(int row,int col,int n ,int m)
    {
        return (row>=0 && row<n && col>=0 && col<m) ;
    }
    void dfs(int i,int j,vector<vector<bool>> &vis , vector<vector<char>> &mat)
    {
        vis[i][j] = true ;

        int n = mat.size() ;
        int m = mat[0].size() ;

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};

        for(int k=0 ; k<4 ; ++k)
        {
            int n_Row = i+delRow[k];
            int n_Col = j+delCol[k];

            if(check(n_Row,n_Col,n,m) && !vis[n_Row][n_Col] && mat[n_Row][n_Col]=='O')
            {
                dfs(n_Row,n_Col,vis,mat);
            }
        }
    }
public:
    vector<vector<char>> solve(vector<vector<char>>& mat) {
       
       int n = mat.size() ;
       int m = mat[0].size() ;

       vector<vector<bool>> vis(n,vector<bool>(m,false)) ;

       for(int i=0 ; i<n ; ++i)
       {
            for(int j=0 ; j<m ; ++j)
            {
                if(!vis[i][j] && mat[i][j]=='O' && (i==0||i==n-1||j==0 || j==m-1))
                {
                    dfs(i,j,vis,mat);
                }
            }
       }

       for(int i=0 ; i<n ; ++i)
       {
            for(int j=0 ; j<m ; ++j)
            {
                if(!vis[i][j] && mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
       }

       return mat ;
    }
};