class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
      unordered_map<int,int> res;
        
      for(auto i:nums){
        res[i]++;
        if(res[i]>1)
          return true;
      }
      return false;
    }
};