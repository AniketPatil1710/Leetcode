class Solution {
public:
    bool ispalindrome(string s)
    {
        int len = s.length() ;
        int mid = len/2 ;
        for(int i=0 , end = len-1; i<mid ; ++i,--end)
        {
            if(s[i]!=s[end])
            {
                return false ;
            }
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        int len = words.size() ;
        
        for(int i=0 ; i<len ; ++i)
        {
            if(ispalindrome(words[i]))
            {
                return words[i];
            }
        }
        
        return "" ;
        
    }
};