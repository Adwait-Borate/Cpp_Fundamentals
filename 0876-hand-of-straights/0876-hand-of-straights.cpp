class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();

        if(n%groupSize!=0){
            return false;
        }

        map<int,int>omap;
        for(auto& i:hand){
            omap[i]++;
        }

        while(!omap.empty()){
            int current=omap.begin()->first;
            
            for(int i=0;i<groupSize;i++){
                if(omap[current+i]==0){
                    return false;
                }

                omap[current+i]--;
                if(omap[current+i]==0){
                    omap.erase(current+i);
                }
            }

        }
        return true;
    }
};