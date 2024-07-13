class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>umap;
        int n=grid.size();
        int cnt=0;
        vector<int>vec;
        for(int i=0;i<n;i++){
            umap[grid[i]]++;
        }
        
        for(int col=0;col<n;col++){
            vec.clear();
           for(int row=0;row<n;row++){
            vec.push_back(grid[row][col]);
           }
           cnt+=umap[vec];
        }

        
          return cnt;
    }
    
};