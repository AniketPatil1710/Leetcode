class Solution {
public:
    string minWindow(string s, string t) {
        /*
        if(s.size()==0 or s.size()<t.size() )
        {
            return "";
        }
        
        unordered_map<char,int> mp;
        string ans = "";
        
        for(int i=0 ; i<t.size() ; ++i)
        {
            mp[t[i]]++ ;
        }
        
        int cnt = 0 ;
        int start = 0 ;
        int min_length = INT_MAX ;
        int min_left = 0;
        
        for(int i=0 ; i<s.size() ; ++i)
        {
            if(mp.find(mp[s[i]])!=mp.end())
            {
                mp[s[i]]--;
            
                if(mp[s[i]]>=0)
                {
                    cnt++;
                }
            }
            
            while(cnt==t.size())
            {
                if(min_length>i-start+1)
                {
                    min_length = i-start+1 ;
                    min_left = start ;
                }
                
                if(mp.find(s[start])!=mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]]>0)
                    {
                        cnt--;
                    }
                }
                
                start++;
            }
        }
        
        for(int i=min_left ; i<=min_left+min_length ; ++i)
        {
            ans+=s[i];
        }
        
        if(min_length > s.length())
        {
            return "";
        }
        return ans;*/
        int n = t.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[t[i]]++;
    }
   
    int i = 0, j = 0, count = mp.size();
    string ans;
    while(j<s.size()){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
       
            if(mp[s[j]] == 0) count--;
           
            while(count == 0){
                if(ans == ""){
                    ans = s.substr(i,j-i+1);
                }
                else if(j-i+1 < ans.size()){
                ans = s.substr(i,j-i+1);
                }
           
                if(mp.find(s[i]) != mp.end()){
                    if(mp[s[i]] == 0){
                        count++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }
           
        }
            j++;
       
    }
   
    return ans;
        
    }
};