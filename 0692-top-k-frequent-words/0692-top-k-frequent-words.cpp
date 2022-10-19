class Solution {
public:
    vector<string> topKFrequent(vector<string>& wd, int k) {
        map<string,int>mp;
        
        for(auto it:wd)
            mp[it] += 1;
        vector<string>v;

        for(auto it:mp)
            v.push_back(it.first);

        sort(v.begin(),v.end(),[&](const string& a,const string& b ){
            if(mp[a]!=mp[b])
                return mp[a] > mp[b];
            return a<b;
        });
        return vector<string>(v.begin(),v.begin()+ k);   
    }
};