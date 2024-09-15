#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPaths(TreeNode* node, int targetSum, vector<int>& path, int currentSum) {
    if (!node) return;

    path.push_back(node->val);
    currentSum += node->val;

    if (!node->left && !node->right && currentSum == targetSum) {
        for (int val : path) cout << val << " ";
        cout << endl;
    }

    findPaths(node->left, targetSum, path, currentSum);
    findPaths(node->right, targetSum, path, currentSum);

    path.pop_back();
}

void printPaths(TreeNode* root, int targetSum) {
    vector<int> path;
    findPaths(root, targetSum, path, 0);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    printPaths(root, targetSum);

    return 0;
}
