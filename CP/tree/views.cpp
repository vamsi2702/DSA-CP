#include <bits/stdc++.h>
using namespace std;

class btree{
public:
    int data;
    btree * left;
    btree * right;

    btree(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

};

void print_arr(vector<int>ans){
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

void print_mat(vector<vector<int>> ans){
    for (int i = 0; i < ans.size(); i ++){
        for (int j = 0; j < ans[i].size(); j ++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void print_left_view(btree * root, vector <int> &ans, int level, int &maxlevel){
    if (root == nullptr){
        return;
    }

    if (level > maxlevel){
        ans.push_back(root->data);
        maxlevel = level;
    }

    print_left_view(root->left, ans, level + 1, maxlevel);
    print_left_view(root->right, ans, level + 1, maxlevel);
}

void print_top_view(btree * root){
    map <int, int> mp;
    queue<pair<btree *, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        btree * node = it.first;
        int level = it.second;
        q.pop();

        if (mp.find(level) == mp.end()){
            mp[level] = node->data;
        }

        if (node->left != nullptr){
            q.push({node->left, level - 1});
        }
        if (node->right != nullptr){
            q.push({node->right, level + 1});
        }
    }

    for (auto it : mp) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

}

void preorder_traversal(btree * root, vector <int> &ans, int level, int &maxlevel){
    if (root == nullptr){
        return;
    }

    if (level > maxlevel){
        maxlevel = level;
    }

    ans.push_back(root->data);
    preorder_traversal(root->left, ans, level + 1, maxlevel);
    preorder_traversal(root->right, ans, level + 1, maxlevel);
}

void preorder_traversal_iterative(btree * root, vector <int> &ans){\
    if (root == nullptr){
        return;
    }

    stack <btree *> st;
    st.push(root);

    while(!st.empty()){
        btree * node = st.top();
        st.pop();

        ans.push_back(node->data);
        if (node->right != nullptr){
            st.push(node->right);
        }
        if (node->left != nullptr){
            st.push(node->left);
        }
    }
    return;

}

vector<vector<int>> levelorder(btree * root){
    vector<vector<int>> ans;
    if (root == nullptr){
        return ans;
    }
    queue <btree *> q;
    q.push(root);

    while (!q.empty()){
        vector<int>level;
        int len = q.size();

        for (int i = 0; i < len; i ++){
            btree * node = q.front();
            q.pop();

            if (node->left != nullptr){
                q.push(node->left);
            }
            if (node->right != nullptr){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int sum_heights(btree * root){
    if (root == nullptr){
        return 0;
    }

    return 1 + max(sum_heights(root->left), sum_heights(root->right));
}

void diameterOfBinaryTree(btree* root, int &max_ans) {
    if (root == nullptr){
        return;
    }

    int lh = sum_heights(root->left);
    int rh = sum_heights(root->right);

    max_ans = max(max_ans, lh + rh);

    diameterOfBinaryTree(root->left, max_ans);
    diameterOfBinaryTree(root->right, max_ans);
}

bool  getPath(btree * root, vector<int>arr, int val){
    if (root == nullptr){
        return false;
    }

    arr.push_back(root->data);

    if (root->data == val){
        return true;
    }

    if (getPath(root->left, arr, val) || getPath(root->right, arr, val)){
        return true;
    }

    arr.pop_back();

}

vector<int> root_to_node(btree * root, int val){
    vector <int> arr;
    if (root == nullptr){
        return arr;
    }

    getPath(root, arr, val);
    return arr;
}

int main(){
    btree * root = new btree(1);
    root->left = new btree(2);
    root->right = new btree(3);
    root->left->left = new btree(4);
    root->left->right = new btree(5);
    root->right->left = new btree(6);
    root->right->right = new btree(7);

    vector<int>res;
    int maxlevel = 0;
    // preorder_traversal(root, res, 1, maxlevel);
    // preorder_traversal_iterative(root, res);
    // print_arr(res);
    // print_top_view(root);
    diameterOfBinaryTree(root, maxlevel);

    cout << maxlevel << endl;
}