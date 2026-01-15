class Solution {
private :
    void dfs(int node , unordered_map<int , vector<int>> &adj , vector<int> &vis , int &v , int &e)
    {
        vis[node] = 1 ;
        v++ ;
        e += adj[node].size() ;

        for(auto &it : adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it,adj,vis,v,e);
            }
        }
    }
     
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        //int E = edges.size() ;
        //vector<int> adj(n) ;

        unordered_map<int , vector<int>> adj ;

        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(n,0) ;
        int num_components = 0 ;

        for(int i=0 ; i<n ; ++i)
        {
            if(vis[i]==1)
            {
                continue ;
            }

            int v = 0 ;
            int e = 0 ;

            dfs(i,adj,vis,v,e) ;

            if((v*(v-1))==e)
            {
                num_components++ ;
            }
        }
        return num_components;
    }
};