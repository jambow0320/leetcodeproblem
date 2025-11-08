#include <algorithm>

using std::max;

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
    int ans = -__INT_MAX__;
    int dfs(TreeNode *u)
    {
        int l = 0, r = 0;
        if(u->left) l = max(dfs(u->left), l);
        if(u->right) r = max(dfs(u->right), r);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};