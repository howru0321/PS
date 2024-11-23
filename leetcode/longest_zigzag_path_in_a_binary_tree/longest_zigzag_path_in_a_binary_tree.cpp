/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class LeftRightMax {
public:
    int left;
    int right;
    int max_num;
};
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        LeftRightMax rightDirection = DFS(root->right);
        ans = max(rightDirection.left + 1, ans);
        ans = max(rightDirection.right, ans);
        ans = max(rightDirection.max_num, ans);

        LeftRightMax leftDirection = DFS(root->left);
        ans = max(leftDirection.right + 1, ans);
        ans = max(leftDirection.left, ans);
        ans = max(leftDirection.max_num, ans);

        return ans;
    }

    LeftRightMax DFS(TreeNode* node){
        if(!node){
            LeftRightMax leafNode;
            leafNode.left=-1;
            leafNode.right=-1;
            leafNode.max_num=-1;
            return leafNode;
        }

        LeftRightMax leftD = DFS(node->left);
        LeftRightMax rightD = DFS(node->right);

        int left = leftD.right + 1;
        int right = rightD.left + 1;
        int max_num = 0;
        max_num=max(max_num,leftD.left);
        max_num=max(max_num,leftD.max_num);
        max_num=max(max_num,rightD.right);
        max_num=max(max_num,rightD.max_num);

        LeftRightMax return_value;
        return_value.left=left;
        return_value.right=right;
        return_value.max_num=max_num;

        return return_value;
    }
};