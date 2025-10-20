#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;
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

    int dfs(TreeNode *u, int depval)
    {
        depval += u->val;
        int max1 = -__INT_MAX__, max2 = -__INT_MAX__;

        if(u->left) max1 = dfs(u->left, depval);
        if(u->right) max2 = dfs(u->right, depval);

        ans = max((long long)max1 + max2 - 2 * depval + u->val, (long long)ans);
        ans = max((long long)max2 - depval + u->val, (long long)ans);
        ans = max((long long)max1 - depval + u->val, (long long)ans);
        ans = max(u->val, ans);

        return max(max(max1, max2), depval);
    }

public:
    int maxPathSum(TreeNode* root) {
        ans = -__INT_MAX__;
        dfs(root, 0);
        return ans;
    }
};