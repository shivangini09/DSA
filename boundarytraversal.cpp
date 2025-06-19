/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        if(!isleaf(root)){
            ans.push_back(root->data);
        }
        addleftboundary(root,ans);
        addleaves(root,ans);
        addrightboundary(root,ans);
        return ans;
    }
private: 
    bool isleaf(Node* root){
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    void addleftboundary(Node* root,vector<int> &ans){
        Node* cur = root->left;
        while(cur){
            if(!isleaf(cur)){
                ans.push_back(cur->data);
            }
            if(cur->left){
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
    }
    
    
    void addrightboundary(Node* root,vector<int> &ans){
        Node* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isleaf(cur)){
                temp.push_back(cur->data);
            }
            if(cur->right){
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    void addleaves(Node* root,vector<int> &ans){
        if(isleaf(root)){
            ans.push_back(root->data);
        }
        if(root->left){
            addleaves(root->left,ans);
        }
        if(root->right){
            addleaves(root->right,ans);
        }
    }
    
};