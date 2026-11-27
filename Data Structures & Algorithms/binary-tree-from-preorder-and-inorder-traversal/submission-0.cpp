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
TreeNode* build(vector<int>&preorder,int st_p,int end_p,vector<int>&inorder,int st_i,int end_i,unordered_map<int,int>&mp){
    if(st_i > end_i || st_p > end_p)return nullptr;

    TreeNode* root = new TreeNode(preorder[st_p]);
    int idx = mp[preorder[st_p]];
    int remain = idx-st_i;

    root->left = build(preorder,st_p+1,st_p+remain,inorder,st_i,idx-1,mp);
    root->right = build(preorder,st_p+remain+1,end_p,inorder,idx+1,end_i,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,0,n-1,inorder,0,n-1,mp);
    }
};
