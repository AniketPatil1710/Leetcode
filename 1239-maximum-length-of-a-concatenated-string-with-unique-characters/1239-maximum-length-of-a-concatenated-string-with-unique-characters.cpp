class Solution {
public:
    bool isUnique(string s)
    {
        int freq[26] = {0};
        int len = s.size() ;
        for(int i=0 ; i<len ; ++i)
        {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>1)
            {
               return false ;    
            }
        }
        return true ;
    }
    
    int maxLength(vector<string>& arr) {
        queue<string> que ;
        int len = arr.size() ;
        que.push("");
        
        int i , j , cl , nl=1 , ml=0 ;
        
        for(i=0 ; i<len ; ++i)
        {
            cl = nl ;
            for(j=0 ; j<cl ; j++)
            {
                que.push(que.front());
                string ns = que.front()+arr[i] ;
                if(isUnique(ns))
                {
                    que.push(ns);
                    nl++;
                }
                que.pop();
            }
        }
        
        while(!que.empty())
        {
            cout<<que.front()<<" ";
            int stlen = que.front().size() ;
            ml = max(ml,stlen);
            que.pop();
        }
        return ml;
    }
};