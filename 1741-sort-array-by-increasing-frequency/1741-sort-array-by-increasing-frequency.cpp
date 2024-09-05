class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (auto& i : nums) {
            umap[i]++;
        }

        // Define the comparator lambda
        auto comp = [&](int n1, int n2) {
            if (umap[n1] == umap[n2]) {
                return n1 > n2; // For equal frequency, sort by value in descending order
            } else {
                return umap[n1] < umap[n2]; // For different frequency, sort by frequency in ascending order
            }
        };

        // Use decltype to define the type of the comparator
        using Comparator = decltype(comp);

        // Sort with the defined comparator
        sort(nums.begin(), nums.end(), Comparator(comp));

        return nums;
    }
};