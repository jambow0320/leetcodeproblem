#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 按层序数组构建二叉树，"null" 表示空节点
TreeNode *buildTree(const vector<string> &nodes, unordered_map<int, TreeNode *> &dict)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    dict[root->val] = root;

    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)nodes.size())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (i < (int)nodes.size() && nodes[i] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[i]));
            dict[cur->left->val] = cur->left;
            q.push(cur->left);
        }
        ++i;

        if (i < (int)nodes.size() && nodes[i] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[i]));
            dict[cur->right->val] = cur->right;
            q.push(cur->right);
        }
        ++i;
    }
    return root;
}

class Solution
{
public:
    int dfs(TreeNode *u)
    {
        if(!u || _ans) return 0;
        int fg = 0;
        if(u -> left != NULL)
            fg |= dfs(u -> left);
        if(_ans) return fg;
        if(u -> right != NULL)
            fg |= dfs(u -> right);
        if(_ans) return fg;
        fg |= ((u == _p) | ((u == _q) << 1));
        if(fg == 3 && _ans == NULL) _ans = u;
        return fg;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        _p = p;
        _q = q;
        _ans = NULL;
        dfs(root);
        return _ans;
    }

private:
    TreeNode *_p, *_q, *_ans;
};

int main()
{
    // 题目给定输入
    vector<string> arr = {"3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4"};
    int pVal = 5, qVal = 1;

    // 构建树并索引每个值到节点指针
    unordered_map<int, TreeNode *> dict;
    TreeNode *root = buildTree(arr, dict);

    // 获取 p、q 节点
    TreeNode *p = dict.count(pVal) ? dict[pVal] : nullptr;
    TreeNode *q = dict.count(qVal) ? dict[qVal] : nullptr;

    Solution sol;
    TreeNode *ans = sol.lowestCommonAncestor(root, p, q);

    if (ans)
    {
        cout << "LCA(" << pVal << ", " << qVal << ") = " << ans->val << endl;
    }
    else
    {
        cout << "LCA not found." << endl;
    }

    return 0;
}