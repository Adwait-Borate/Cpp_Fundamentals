class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26,0);

        for(auto &s:sentence){
            int index=s-'a';
            arr[index]++;
        }

        for(auto &count : arr){
            if(count==0)
            return false;
        }
        return true;
    }
};