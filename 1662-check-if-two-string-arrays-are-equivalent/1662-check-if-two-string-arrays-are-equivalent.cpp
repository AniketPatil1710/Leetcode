class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string st1 = "" ;
        string st2 = "" ;
        
        int len1 = word1.size() ;
        int len2 = word2.size() ;
        
        for(int i = 0 ; i<len1 ; ++i)
        {
            st1+=word1[i] ;
        }
        for(int i=0 ; i<len2 ; ++i)
        {
            st2+=word2[i] ;
        }
        
        if(st1==st2)
        {
            return true ;
        }
        return false;
        
    }
};