class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mp;
        
        int len = words.size();
        
        for(int i=0 ; i<len ; ++i)
        {
            mp[words[i]]++;
        }
        
        int ans=0 , m=0 ;
        bool flag = false ;
        
        for(auto x:mp)
        {
            string s = x.first ;
            string t = s ;
            reverse(s.begin(),s.end());
            if(s==t)
            {
                ans+=x.second/2 ;
                if(x.second%2)
                {
                    flag = true ;
                }
            }
            else
            {
                if(mp.count(s))
                {
                    ans+=min(x.second,mp[s]) , mp.erase(s) ;
                }
            }
        }
        
        ans = ans*4 ;
        
        if(flag)
        {
            ans+=2;
        }
        
        return ans ;
    }
};