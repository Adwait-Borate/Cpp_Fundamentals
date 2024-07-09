class Solution {
public:
    void reverseStringRecursion(vector<char>& s, int start, int end){
        if(start>=end){return;}
        swap(s[start],s[end]);
        reverseStringRecursion(s,start+1,end-1);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        reverseStringRecursion(s,0,n-1);
    }
};