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
class Solution {
public:
    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftsum=sum(root->left);
        int rightsum=sum(root->right);
        return root->val+leftsum+rightsum;
    }
    void helper(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(abs(sum(root->left)-sum(root->right)));
        helper(root->left,ans);
        helper(root->right,ans);
    }
    int findTilt(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int s=0;
        for(int i=0;i<ans.size();i++){
            s+=ans[i];
        }
        return s;
    }
};