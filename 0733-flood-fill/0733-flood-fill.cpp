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

    void dfs(int i,int j,vector<int> &dx,vector<int> &dy,vector<vector<int>> &ans ,vector<vector<int>> &image ,int in_col ,int color)
    {
        ans[i][j] = color ;

        int n = image.size() ;
        int m = image[0].size() ;

        for(int k=0 ; k<4 ; ++k)
        {
            int row = i + dx[k] ;
            int col = j + dy[k] ;

            if(check(n,m,row,col) && (image[row][col] == in_col) && (ans[row][col]!=color))
            {
                dfs(row,col,dx,dy,ans,image,in_col,color);
            }

        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { 

        vector<vector<int>> ans = image ;

        int in_col = image[sr][sc] ;

        vector<int> dx = {-1,0,+1,0};
        vector<int> dy = {0,+1,0,-1};

        dfs(sr,sc,dx,dy,ans,image,in_col,color);

        return ans ;
    }
};