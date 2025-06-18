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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n = q.size();
            vector<int> row(n);
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){                 
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                int index = flag? i : n-1-i;        // deciding whether the array will be filled in reverse or default manner.
                row[index]=node->val;
            }
            result.push_back(row);
            flag = !flag;        // we change the flag ofcourse , to make it zigzag!
        }
        return result;
    }
};