class Solution {
public:
    long long appealSum(string s) {
   
        vector<int> ans(26) ;
        long len = s.size() ;
        long sum = 0 ;
        
        for(int i=0 ; i<len ; ++i)
        {
            ans[s[i]-'a'] = i+1 ;
            for(int j: ans)
            {
                sum+=j;
            }
        }
        return sum ;
    }
};