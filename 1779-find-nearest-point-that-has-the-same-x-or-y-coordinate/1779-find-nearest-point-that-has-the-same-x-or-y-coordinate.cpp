class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        int n = points.size() ;

        int check = 0 ;
        int min_ind ;
        int min_dst = INT_MAX ;

        for(int i=0 ; i<n ; ++i)
        {
            int c_x = points[i][0] ;
            int c_y = points[i][1] ;

            if(x==c_x || y==c_y)
            {
                check = 1 ;
                int dst = abs(x-c_x) + abs(y-c_y) ;
                if(dst<min_dst)
                {
                    min_dst = dst ;
                    min_ind = i ;
                }

            }
        }
        if(check==0)
        {
            return -1 ;
        }
        return min_ind ;
        
    }
};