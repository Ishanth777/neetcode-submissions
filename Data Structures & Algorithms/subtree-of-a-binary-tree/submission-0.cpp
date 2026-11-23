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
bool help(TreeNode* root,TreeNode* temp){
    if(root==nullptr && temp==nullptr)return true;
    if(root==nullptr || temp==nullptr)return false;

    if(root->val != temp->val)return false;
    return help(root->left,temp->left) && help(root->right,temp->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)return false;
        if(root->val == subRoot->val){
            if(help(root,subRoot))return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
