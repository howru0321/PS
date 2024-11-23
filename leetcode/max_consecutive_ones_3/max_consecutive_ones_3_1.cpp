class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int ans=-1;
        int start=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num==0){
                if(q.size()==k){
                    int length=i-start;
                    if(length>ans){
                        ans=length;
                    }
                    if(k!=0){
                        start = q.front()+1;
                        q.pop();
                    }else{
                        start=i+1;
                    }
                }
                if(k!=0){
                    q.push(i);
                }
            }
        }
        int length=nums.size()-start;
        if(length>ans){
            ans=length;
        }
        return ans;
    }
};