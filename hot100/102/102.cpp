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
    void dfs(TreeNode *u, int dep, vector<vector<int>> &ans)
    {
        if(!u) return ;
        if(ans.size() <= dep)
            ans.resize(dep + 1);
        ans[dep].push_back(u->val);
        dfs(u->left, dep + 1, ans);
        dfs(u->right, dep + 1, ans);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ans.reserve(2010);
        dfs(root, 0, ans);
        return ans;
    }
};