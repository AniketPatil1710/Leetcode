class Solution {
public:
    int climbStairs(int n) {
        if (n<=3)
        {
            return n ;
        }
        int tmp;
        int x=1 , y=2 ;
        for(int i=3 ; i<n ; ++i)
        {
            tmp=y;
            y+=x ;
            x = tmp ;
        }
        
        return (x+y);
    }
};