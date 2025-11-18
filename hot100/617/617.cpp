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
    TreeNode* dfs(TreeNode *u1, TreeNode *u2)
    {
        if(!u1 && !u2) return nullptr;
        TreeNode *tmp = u1 ? u1 : u2;
        tmp->left = dfs(u1 ? u1->left : nullptr, u2 ? u2->left : nullptr);
        tmp->right = dfs(u1 ? u1->right : nullptr, u2 ? u2->right : nullptr);
        if(u1 && u2) tmp->val = u1->val + u2->val;
        return tmp;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};