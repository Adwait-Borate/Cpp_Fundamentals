class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>umap;
        vector<int>ans;

        for(auto &i:nums){
            umap[i]++;
        }

        for(auto &it:umap){
            if(it.second!=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};