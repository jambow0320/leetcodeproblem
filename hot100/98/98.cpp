#include <climits>

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
    bool dfs(TreeNode *u, long long valMin, long long valMax)
    {
        if(u->val > valMax || u->val < valMin) return false;

        if(u->left)
        {
            if(!dfs(u->left, valMin, (long long)u->val - 1)) 
                return false;
        }
        
        if(u->right)
        {
            if(!dfs(u->right, (long long)u->val + 1, valMax))
                return false;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};