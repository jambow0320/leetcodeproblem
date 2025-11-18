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
    bool dfs(TreeNode *u1, TreeNode *u2)
    {
        if(!u1 && !u2) return true;
        if((u1 && !u2) || (!u1 && u2)) return false;
        if(u1->val != u2->val) return false;
        
        if(!dfs(u1->left, u2->right)) return false;
        if(!dfs(u1->right, u2->left)) return false;
        return true;
    }

public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
};