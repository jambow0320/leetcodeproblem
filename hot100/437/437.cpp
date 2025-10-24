// 记得开long long

#include <unordered_map>

using std::unordered_map;

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
    unordered_map<long long, int> pre_cnt;
    int ans = 0, _target;

    void dfs(TreeNode *u, long long dep)
    {
        dep += u->val;
        long long key = dep - _target;
        auto it = pre_cnt.find(key);
        if(it != pre_cnt.end())
            ans += it->second;
        ++pre_cnt[dep];

        if(u->left) dfs(u->left, dep);
        if(u->right) dfs(u->right, dep);

        --pre_cnt[dep];
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        ans = 0;
        _target = targetSum;
        ++pre_cnt[0];
        dfs(root, 0);
        pre_cnt.clear();
        return ans;
    }
};