class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        int size = nums.size();
       for(int i=0 ; i<size ; ++i)
       {
           if(mp.find(target-nums[i])==mp.end())
           {
               mp[nums[i]] = i ;
           }
           else
           {
               return {mp[target-nums[i]],i};
           }
       }
        return {-1,-1};
    }
};