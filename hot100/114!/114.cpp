/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/

/*
要求额外空间O(1)，就不能dfs了

可以对于某个点来说，去找它的左子树的最右节点(代码中是tmp)，他就相当于是左子树的最后一个，
然后它的后面连的就是右子树，直接把右子树接到他上面
暴力去找这个前驱点，复杂度是对的，在寻找前驱节点的过程中，每个节点最多被额外访问一次。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
public:
    TreeNode* flatten(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *l = root->left, *r = root->right;
        root->left = nullptr;
        root->right = nullptr;
        TreeNode *tmp = nullptr;
        if(l)
        {
            root->right = l;
            tmp = flatten(l);
        }
        if(!tmp) tmp = root;
        if(r)
        {
            tmp->right = r;
            tmp = flatten(r);
        }
        return tmp;
    }
};*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;

        TreeNode *now = root;
        while(now)
        {
            if(now->left)
            {
                TreeNode *tmp = now->left;
                while(tmp->right)
                    tmp = tmp->right;
                
                tmp->right = now->right;
                TreeNode *next = now->left;
                now->left = nullptr; now->right = next;
            }
            now = now->right;
        }

        return ;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    s.flatten(root);

    return 0;
}