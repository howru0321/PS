class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sums;
        left_sums.push_back(0);
        for(int i=0;i<nums.size();i++){
            int prev_left_sum=left_sums[i];
            int left_sum=prev_left_sum+nums[i];
            left_sums.push_back(left_sum);
        }

        int total_sum=left_sums.back();

        for(int i=0;i<nums.size();i++){
            if((total_sum-nums[i])==(2*left_sums[i])){
                return i;
            }
        }
        return -1;
    }
};