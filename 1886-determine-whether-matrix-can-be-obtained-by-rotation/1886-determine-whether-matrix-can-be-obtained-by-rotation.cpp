class Solution {
private:
void rotate_ninty_degree(vector<vector<int>>& mat , int n)
{
    for(int i=0 ; i<n ; ++i)
    {
        for(int j=0 ; j<i ; ++j)
        {
            swap(mat[i][j],mat[j][i]) ;
        }
    }

    for(int i=0 ; i<n ; ++i)
    {
        reverse(mat[i].begin() , mat[i].end()) ;
    }
}
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int n = mat.size() ;

        for(int i=0 ; i<=4 ; ++i)
        {
            rotate_ninty_degree(mat,n) ;
            if(mat==target)
            {
                return true ;
            }
            
        }
        
        return false ;
    }
};
