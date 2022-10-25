class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       /* 
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
    */
            int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        while (i1 < word1.size() && i2 < word2.size()){
            if (word1[i1][j1] != word2[i2][j2]){
                return 0;
            }
            j1++, j2++;
            if (j1 >= word1[i1].size()){
                i1++, j1 = 0;
            }
            if (j2 >= word2[i2].size()){
                i2++, j2 = 0;
            }
        }
        return i1 == word1.size() and i2 == word2.size();
        
        
    }
};