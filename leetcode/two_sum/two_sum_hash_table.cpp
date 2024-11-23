class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> hash_table;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,vector<int>>::iterator iter = hash_table.find(nums[i]);
            if(iter!=hash_table.end()){
                (*iter).second.push_back(i);
            }
            else{
                vector<int> v = {i};
                hash_table.insert({nums[i],v});
            }
        }

        for(int i=0;i<nums.size();i++){
            int first = nums[i];
            unordered_map<int,vector<int>>::iterator scd = hash_table.find(target-first);
            if(scd==hash_table.end()){
                continue;
            }
            vector<int> v=(*scd).second;
            for(int j=0;j<v.size();j++){
                int k=v[j];
                if(i!=k){
                    return vector<int>{i,k};
                }
            }
            continue;
        }
        return vector<int>{0,9};
    }
};