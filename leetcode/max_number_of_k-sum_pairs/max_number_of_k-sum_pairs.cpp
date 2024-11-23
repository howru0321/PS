class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> cache;

        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(k-num<=0){
                continue;
            }
            auto iter = cache.find(k-num);
            if(iter==cache.end()){
                auto num_cache=cache.find(num);
                if(num_cache!=cache.end()){
                    (*num_cache).second++;
                }else{
                    cache.insert({num,1});
                }
                continue;
            }
            if((*iter).second!=1){
                (*iter).second--;
            }else{
                cache.erase(iter);
            }
            ans++;
        }

        return ans;
    }
};