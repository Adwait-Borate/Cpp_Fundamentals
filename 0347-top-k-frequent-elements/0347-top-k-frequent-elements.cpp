class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies of each element
        unordered_map<int, int> umap;
        for (auto& num : nums) {
            umap[num]++;
        }

        // Step 2: Define the comparator function
        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second; // Min-heap based on frequency
            }
        };
        
        // Use the comparator function in the priority_queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        // Add elements to the min-heap
        for (const auto& entry : umap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop(); // Ensure the heap size is k
            }
        }

        // Step 3: Extract elements from the heap to form the result
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }

        // The heap gives the elements in the order of increasing frequency, so reverse the result
        reverse(ans.begin(), ans.end());

        return ans;
    }
};