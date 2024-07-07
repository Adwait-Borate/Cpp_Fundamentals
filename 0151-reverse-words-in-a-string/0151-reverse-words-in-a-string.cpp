#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    std::stack<std::string> Reverse(std::string str) {
        std::stack<std::string> myStack;
        std::string word = "";
        int k = 0;
        int len = str.size();

        for (int i = 0; i <= len; i++) {
            if (i == len || str[i] == ' ') {
                word = str.substr(k, i - k);
                if (!word.empty()) { // Only push non-empty words
                    myStack.push(word);
                }
                k = i + 1; // Move past the space
            }
        }

        return myStack;
    }

    std::string reverseWords(std::string s) {
        std::stack<std::string> myStack = Reverse(s);
        std::string ans = "";

       while (!myStack.empty()) {
        if (myStack.size() == 1) {
            ans += myStack.top(); // Add the last word without a space
        } else {
            ans += myStack.top() + " "; // Add space after each word except the last one
        }
        myStack.pop();
    }

        return ans;
    }
};

