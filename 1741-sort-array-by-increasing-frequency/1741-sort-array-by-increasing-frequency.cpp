class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int, int> umap;
        for (auto& i : nums) {
            umap[i]++;
        }

        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (umap[n1] == umap[n2]) {
                return n1 > n2;
            } else {
                return umap[n1] < umap[n2];
            }
        });

        return nums;
    }
};