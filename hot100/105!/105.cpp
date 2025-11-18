/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

/*
一直没想清楚怎么在先序遍历里划分左子树和右子树，其实用左子树的size就可以了，左子树的size可以通过inorder中的根的序得到
然后弄个hashmap去找对应的inorder就行
*/

#include <bits/stdc++.h>
#include <unordered_map>

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
    unordered_map<int, int> pos;

    void dfs(int prel, int prer, int inl, int inr, const vector<int> &preorder, const vector<int> &inorder, TreeNode *&father)
    {
        TreeNode *u = new TreeNode(preorder[prel]);
        father = u;
        if(prel == prer)
        {
            return ;
        }

        int u_preid = preorder[prel];
        int u_inid = pos[u_preid];


        if(u_inid > inl)
        {
            dfs(prel + 1, prel + u_inid - inl, inl, u_inid - 1, preorder, inorder, u->left);
        }
        if(u_inid < inr)
        {
            dfs(prel + u_inid - inl + 1, prer, u_inid + 1, inr, preorder, inorder, u->right);
        }
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;

        for(int i = 0; i < inorder.size(); ++i)
            pos[inorder[i]] = i;

        TreeNode *dummyhead = new TreeNode();
        dfs(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, dummyhead->left);

        TreeNode *tmp = dummyhead->left;
        delete dummyhead;
        return tmp;
    }
};