/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        // Use map to store the first node at each horizontal distance
        map<int, int> mpp;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            // If this horizontal distance is not seen before, store it
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            if (node->left) {
                q.push({node->left, line - 1});
            }
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }

        // Extract the stored values in order of horizontal distance
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
