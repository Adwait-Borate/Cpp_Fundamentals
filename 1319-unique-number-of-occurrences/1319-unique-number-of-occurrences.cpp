class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>umap;
        bool ans=false;
        for(auto& i:arr){
            umap[i]++;
        }
      
        unordered_set<int>uset;
        for(auto& it:umap){
            uset.insert(it.second);
        }

        int usetSize=uset.size();
        int umapSize=umap.size();
        
        if(usetSize==umapSize){
            ans=true;
        }else{
            ans=false;
        }

        return ans;
    }
};