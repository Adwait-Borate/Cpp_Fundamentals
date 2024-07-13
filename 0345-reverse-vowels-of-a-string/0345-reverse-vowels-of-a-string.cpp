class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> uset;
            uset.insert('a');uset.insert('e');uset.insert('i');uset.insert('o');
        uset.insert('u');uset.insert('A');uset.insert('E');uset.insert('I');
        uset.insert('O');uset.insert('U');
        
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<=j){
            if(uset.count(s[i]) && uset.count(s[j])){
               swap(s[i],s[j]);i++;j--;
            }else{
                if(!uset.count(s[i]) && uset.count(s[j])){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return s;
    }
};


// class Solution {
// public:
//     string reverseVowels(string s) {
//         unordered_set<char> uset;
//         uset.insert('a');uset.insert('e');uset.insert('i');uset.insert('o');
//         uset.insert('u');uset.insert('A');uset.insert('E');uset.insert('I');
//         uset.insert('O');uset.insert('U');

//         int n = s.length();
//         int i = 0;
//         int j = n - 1;

//         while (i < j) {
//             if (uset.count(s[i]) && uset.count(s[j])) {
//                 swap(s[i], s[j]);
//                 i++;
//                 j--;
//             } else {
//                 if (!uset.count(s[i])) i++;
//                 if (!uset.count(s[j])) j--;
//             }
//         }
//         return s;
//     }
// };
