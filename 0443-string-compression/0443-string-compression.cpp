#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0, i = 0;
        
        while (i < n) {
            char curr_char = chars[i];
            int count = 0;
            
            
            while (i < n && chars[i] == curr_char) {
                count++;
                i++;
            }
            
            
            chars[index] = curr_char;
            index++;
            
          
            if (count > 1) {
                string count_str = to_string(count);
                for (auto &ch : count_str) {
                    chars[index] = ch;
                    index++;
                }
            }
        }
        
        return index;
    }
};
