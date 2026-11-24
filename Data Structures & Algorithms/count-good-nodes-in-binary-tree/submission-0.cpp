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
void help(TreeNode* root,int &count,int maxi){
    if(!root)return;
    if(root->val >= maxi){
        maxi = root->val;
        count++;
    }
    help(root->left,count,maxi);
    help(root->right,count,maxi);
}
    int goodNodes(TreeNode* root) {
        int count = 0;
        help(root,count,-1e5);
        return count;
    }
};
