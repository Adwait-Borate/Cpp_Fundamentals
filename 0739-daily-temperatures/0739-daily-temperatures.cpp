class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>index;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!index.empty() && temperatures[i]>=temperatures[index.top()]){
                index.pop();
            }

            if(index.empty()){
                ans[i]=0;
            }else{
                ans[i]=index.top()-i;
            }
            index.push(i);
        }
        return ans;
    }
};