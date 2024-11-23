class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=-1;
        int start=0;
        int zero_num=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==0){
                zero_num++;
            }

            while(zero_num>k){
                if(nums[start]==0){
                    zero_num--;
                }
                start++;
            }

            ans=max(ans,end-start+1);
        }

        return ans;
    }
};