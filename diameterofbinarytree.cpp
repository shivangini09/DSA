class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateHeight(root,diameter);
        return diameter;
    }
    
private:
    // Helper function to calculate height and update the diameter
    int calculateHeight(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0; // Height of an empty node is 0
        }
        
        // Recursively calculate the height of left and right subtrees
        int leftHeight = calculateHeight(node->left, diameter);
        int rightHeight = calculateHeight(node->right, diameter);
        
        // Update the diameter to the maximum value found
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};
