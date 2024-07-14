// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();
//         int j;
//         int len = 0;
//         for (int i = 0; i < n; i++) {
//             j = i + 1;
//             while (j < n) {
//                 if (nums[i] == nums[j]) {
//                     len = j - i;
//                     if (len <= k) {
//                         return true;
//                     }
//                 }
//                 j++;
//             }
//         }
//         return false;
//     }
// }; // GIVING TLE

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) != umap.end()) {
                if (i - umap[nums[i]] <= k) {
                    return true;
                }
            }
            umap[nums[i]] = i;
        }
        return false;
    }
};
