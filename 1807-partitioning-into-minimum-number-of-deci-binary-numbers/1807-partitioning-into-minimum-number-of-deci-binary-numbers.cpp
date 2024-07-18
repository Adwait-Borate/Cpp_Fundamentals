class Solution {
public:
    int minPartitions(string n) {
        int len=n.length();
        int maxi=INT_MIN;
        int num;
        int i=0;
        while(i<len){
           num=n[i]-'0';
           maxi=max(maxi,num);
           i++;
        }
        return maxi;
    }
};
