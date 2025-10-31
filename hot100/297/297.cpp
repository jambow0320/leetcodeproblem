// 注意负权值

#include <string>
#include <algorithm>

using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string encoderValToString(int val)
    {
        string str = "";
        int fg = 0;
        if(val < 0) { val = -val; fg = 1; }
        while(val)
        {
            str += (char)((val % 10) + '0');
            val /= 10;
        }
        std::reverse(str.begin(), str.end());
        if(!fg) str += '/';
        else str += '|';
        return str;
    }

    int decoderStringToVal(string &str, int &pos)
    {
        int val = 0;
        while(1)
        {
            if(pos >= str.size()) break;
            if(str[pos] == '/' || str[pos] == '|') break;
            val *= 10;
            val += (int)(str[pos++] - '0');
        }
        if(str[pos++] == '|') val = -val;
        return val;
    }

    void dfsEncoder(TreeNode *u, string &str)
    {
        str += encoderValToString(u->val);
        if(u->left) dfsEncoder(u->left, str);
        else str += '!';
        if(u->right) dfsEncoder(u->right, str);
        else str += '!';
    }

    int pos;
    void dfsDecoder(TreeNode *&u, string &str)
    {
        int val = decoderStringToVal(str, pos);
        u = new TreeNode(val);

        if(str[pos] == '!')
            ++pos;
        else
            dfsDecoder(u->left, str);

        if(str[pos] == '!')
            ++pos;
        else
            dfsDecoder(u->right, str);
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoderStr("");
        if(root == nullptr) return encoderStr;
        dfsEncoder(root, encoderStr);
        return encoderStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        if(data.empty()) return root;
        pos = 0;
        dfsDecoder(root, data);
        return root;
    }
};

Codec sol;

int main()
{
    sol.deserialize("1/2/!!3/4/!!5/!!");
    return 0;
}