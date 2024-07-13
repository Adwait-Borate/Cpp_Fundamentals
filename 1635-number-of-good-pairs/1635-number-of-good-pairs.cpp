class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>umap;
        int total=0;
        for(auto& i:nums){
            umap[i]++;
        }

        for(auto& it:umap){
           int n=it.second;
           total+=(n*(n-1))/2;
        }

        return total;
    }
};