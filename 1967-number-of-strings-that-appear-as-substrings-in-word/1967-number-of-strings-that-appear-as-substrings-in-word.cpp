class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        int len = patterns.size() ;
        for(int i=0;i<len;i++)
        {
            if(word.find(patterns[i])==-1)
            {
                continue;
            }
            else
            {
                count++;
            }
        }
        return count;    
    }
};