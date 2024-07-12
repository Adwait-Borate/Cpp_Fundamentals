class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        for(auto &it : matches) {
            int lose = it[1];
            lost[lose]++;
        }
        
        vector<int>alwaysWin;
        vector<int>oneLost;
        
        for(auto &it : matches) {
            int lose = it[1];
            int win  = it[0];
            
            if(lost[lose] == 1) {
                oneLost.push_back(lose);
            }
            if(lost.find(win) == lost.end()) {
                alwaysWin.push_back(win);
                lost[win] = 2;
            }
            
        }
        
        sort(begin(alwaysWin), end(alwaysWin));
        sort(begin(oneLost), end(oneLost));
        
        return {alwaysWin, oneLost};
        
    }
};

