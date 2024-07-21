class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int count = 0;
        int i = n - 2;
        int res = 0;
        while (count != n / 3) {
            res += piles[i];
            i -= 2;
            count++;
        }

        return res;
    }
};