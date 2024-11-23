Class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=0;

        for(i=0;i<nums.size();i++){
            int first=nums[i];
            for(int j=i+1;j<nums.size();j++){
                int second=nums[j];
                if(first+second==target){
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>{0,0};
    }
};