#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int dfs(TreeNode *u, int dep)
    {
        int tmp = dep;
        if(u->left) tmp = max(tmp, dfs(u->left, dep + 1));
        if(u->right) tmp = max(tmp, dfs(u->right, dep + 1));
        return tmp;
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 1);
    }
};