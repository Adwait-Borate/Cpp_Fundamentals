class Solution {
public:
    bool isPalindrome(std::string s) {
        int len = s.size();
        std::string word = "";
        for (auto &ch : s) {
            if (std::isalnum(ch)) {
                word += std::tolower(ch);
            }
        }
        std::string reversed = word;
        std::reverse(reversed.begin(), reversed.end());

        if(word == reversed){
            return true;
        }
        return false;
    }
};