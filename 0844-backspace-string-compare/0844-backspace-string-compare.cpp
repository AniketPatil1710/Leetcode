class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st ;
        int len1 = s.size() ;
        int len2 = t.size() ;
        int i ;
        for(i=0 ; i<len1 ; ++i)
        {
            if(s[i]=='#')
            {
                if(st.size()==0)
                {
                    continue;
                }
                st.pop() ;
            }
            else
            {
                st.push(s[i]);
            }
        }
        string st1 = "" ;
        while(!st.empty())
        {
            st1+=st.top() ;
            st.pop() ;
        }
        for(i=0 ; i<len2 ; ++i)
        {
            if(t[i]=='#')
            {
                if(st.size()==0)
                {
                    continue;
                }
                st.pop();
            }
            else
            {
                st.push(t[i]);
            }
        }
        string st2= "";
        while(!st.empty())
        {
            st2+=st.top();
            st.pop();
        }
        if(st1==st2)
        {
            return true;
        }
        return false;
    }
};