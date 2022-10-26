class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pr(n,0);
        pr[0]=nums[0];
        for(int i=1;i<n;i++){
            pr[i]=pr[i-1]+nums[i];
        }
        unordered_map<int,int>mapp;
        mapp[0]++;
        for(int i=1;i<n;i++){
        if(mapp[(pr[i]%k)]!=0){
            return true;
        }
        else{
            mapp[pr[i-1]%k]++;
        }
    }
        return false;    
    }
};