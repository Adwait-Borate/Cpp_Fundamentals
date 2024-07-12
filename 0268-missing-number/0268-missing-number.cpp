class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int>umap;
        int n=nums.size();
        int ans;
        for (auto &i:nums) {
            umap[i]++;
        }

        for (int i=0;i<=n;i++) {
            if (umap[i]==0) {
                ans=i;
                break;
            }
        }
        return ans;
    }
};