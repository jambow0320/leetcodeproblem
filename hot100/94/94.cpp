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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();

        stack<pair<bool, TreeNode*>> sta;
        vector<int> ans;

        sta.push(make_pair(1, root));

        while(!sta.empty())
        {
            auto x = sta.top(); sta.pop();
            if(x.first == 1)
            {
                if(x.second->right) sta.push(make_pair(1, x.second->right));
                sta.push(make_pair(0, x.second));
                if(x.second->left) sta.push(make_pair(1, x.second->left));
            }
            else ans.push_back(x.second->val);
        }
        
        return ans;
    }
};