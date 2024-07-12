class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>umap;
        int ans;
        int n=nums.size();
        
        for (auto &i:nums) {
            umap[i]++;
        }

        for(int j=1;j<n;j++) { 
            if(umap[j]>1) { 
                ans=j;
                break;
            }
        }
        return ans;
    }
};