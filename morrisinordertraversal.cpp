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

 // morris inorder soln

class Solution {
public:
    void helper(TreeNode* root, vector<int> &result){
        TreeNode* cur = root;
        while(cur!=nullptr){
            if(cur->left==nullptr){
                result.push_back(cur->val);
                cur=cur->right;
            }
            else{
                // find ip 
                TreeNode* ip = cur->left;
                while(ip->right!=nullptr && ip->right!=cur){
                    ip=ip->right;
                }
                if(ip->right==nullptr){
                    ip->right=cur;
                    cur=cur->left;
                }
                else{
                    ip->right=nullptr;
                    result.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root,result);
        return result;

    }
};