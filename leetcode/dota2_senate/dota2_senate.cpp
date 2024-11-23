class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiants;
        queue<int> dires;
        int n=senate.size();
        for(int i=0;i<senate.size();i++){
            char senator= senate[i];
            if(senator=='R'){
                radiants.push(i);
            }else{
                dires.push(i);
            }
        }

        while(!radiants.empty()&&!dires.empty()){
            int radiant_idx = radiants.front(); radiants.pop();
            int dire_idx = dires.front(); dires.pop();

            if(radiant_idx>dire_idx){
                dires.push(dire_idx+n);
            }else{
                radiants.push(radiant_idx+n);
            }
        }

        return radiants.empty() ? "Dire" : "Radiant";
    }
};