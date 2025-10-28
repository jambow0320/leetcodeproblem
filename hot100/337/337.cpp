#include <utility>
#include <algorithm>

using std::pair;

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
    pair<int, int> dfs(TreeNode *u)
    {
        pair<int, int> dp = std::make_pair(0, u->val);
        pair<int, int> tmp;
        if(u->left)
        {
            tmp = dfs(u->left);
            dp.first += std::max(tmp.second, tmp.first);
            dp.second += tmp.first;
        }
        if(u->right)
        {
            tmp = dfs(u->right);
            dp.first += std::max(tmp.second, tmp.first);
            dp.second += tmp.first;
        }
        return dp;
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return std::max(ans.first, ans.second);
    }
};