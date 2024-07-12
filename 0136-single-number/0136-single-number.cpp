class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans;
        
        for(auto &i:nums) {
            umap[i]++;
        }

        for(auto &it:umap) {
            if(it.second!=2) {
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};
