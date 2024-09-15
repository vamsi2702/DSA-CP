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
    vector <int> res;

    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL) {
            res.push_back(root -> val);
            preorderTraversal(root -> left);
            preorderTraversal(root -> right);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {}; 

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);
        
        return result;
    }
private:
    vector<int> result;
};
class Solution {
public:
    vector<int> helper(TreeNode* node, vector<int>& path) {
        if (node == NULL)
            return path;

        path = helper(node->left, path);
        path.push_back(node->val);
        path = helper(node->right, path);
        return path;
    }
};

