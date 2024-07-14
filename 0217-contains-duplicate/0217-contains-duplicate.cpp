class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap;

        for(auto& i:nums){
            umap[i]++;
        }

        for(int j=0;j<nums.size();j++){
            if(umap[nums[j]]>=2){
                return true;
            }
        }
        return false;
    }
};