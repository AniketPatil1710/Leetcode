class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        vector<int> ans ;
        int len = s.size() ;
        int back,front ;
        int check1=0 , check2=0 ;
        
        for(int i=0 ; i<len ; ++i)
        {
            back = i ;
            front = i ;
            check1=0,check2=0;
            while(back!=-1)
            {
                if(s[back]==c)
                {
                    check1=1;
                    break;
                }
                back--;
            }
            while(front!=len)
            {
                if(s[front]==c)
                {
                    check2=1 ;
                    break;
                }
                front++;
            }
            if(check1 and check2)
            {
               // ans.push_back(abs(front-i));
                ans.push_back(min((abs(i-back)),(abs(front-i))));
            }
            else if(check2)
            {
                //ans.push_back(abs(i-back));
                ans.push_back(abs(front-i));
            }
            else{
                //ans.push_back(min((abs(i-back)),(abs(front-i))));
                ans.push_back(abs(back-i));
            }
        }
        return ans;
    }
};