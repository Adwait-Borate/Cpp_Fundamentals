class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count=0;
        long long substrings=0;

        for(auto &ch: s){
            if(ch==c){
                substrings+=(1+count);
                count++;
            }
        }
        return substrings;
    }
};