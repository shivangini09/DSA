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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;        // Use long long for indices
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second; // Minimum index for the level
            long long first, last;
            
            for (int i = 0; i < size; i++) {               // iterate level nodes 
                auto [node, curIndex] = q.front();
                q.pop();
                curIndex -= minIndex; // Normalize index to prevent overflow
                
                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;
                
                if (node->left) {
                    q.push({node->left, curIndex * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, curIndex * 2 + 2});
                }
            }
            ans = max(ans, static_cast<int>(last - first + 1)); // Cast back to int for result
        }
        
        return ans;
    }
};

