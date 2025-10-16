#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        dfs(root);
        return root;
    }

private:
    void dfs(TreeNode* u)
    {
        std::swap(u->left, u->right);
        if(u->left) dfs(u->left);
        if(u->right) dfs(u->right);
    }
};

int main()
{
    return 0;
}