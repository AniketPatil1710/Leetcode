class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int len = indices.size() ;
        
        for(int i=0 ; i<len ; ++i)
        {
            ans[indices[i]] = s[i];
        }
        return ans ;   
    }
};