/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> listNode;
        for(ListNode* i=head;i!=nullptr;i=i->next){
            int val=(i->val);
            listNode.push_back(val);
        }

        int n=listNode.size();
        int ans=-1;
        for(int i=0;i<n/2;i++){
            int twinSum=listNode[i]+listNode[n-1-i];
            if(twinSum>ans){
                ans=twinSum;
            }
        }
        return ans;
    }
};