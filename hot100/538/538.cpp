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
    int sum = 0;
    void dfs(TreeNode *u)
    {
        if(u->right) dfs(u->right);
        sum += u->val;
        u->val = sum;
        if(u->left) dfs(u->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        sum = 0;
        dfs(root);
        return root;
    }
};