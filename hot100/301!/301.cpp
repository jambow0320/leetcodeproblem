/*
给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

输入：s = "()())()"
输出：["(())()","()()()"]
*/

// 先扫一遍得到最小数量的无效括号，具体维护一个左括号数量，碰到右括号就--
// 触到0还有右括号就意味着这右括号无效了，最后可以得到一个l,r分别代表要删除的左括号和右括号数量
// 再爆搜去找方案就行了，过程中满足左括号数量>=0，最后满足删除的左右括号数量
// 同时要去重方案，可以用hash表，也可以搜的时候注意一点，比如连续的(((，如果要删除一个左括号，优先删最左边的
// 避免_((、(_(、((_这三种方案算重

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::max;
using std::vector;
using std::string;

using namespace std;

class Solution {
private:
    string str;
    int l, r;
    vector<string> ans;

    void dfs(int pos, int score, int _l, int _r, string now)
    {
        if(score < 0 || _l > l || _r > r)
            return ;

        if(pos == str.size())
        {
            if(score == 0)
            {
                ans.push_back(now);
                cout << now << endl;
            }
            return ;
        }

        string tmp = now;
        for(int i = pos; i < str.size(); ++i)
        {
            if(score < 0) break;
            if(i != pos && str[i - 1] == str[i] && (str[i] == '(' || str[i] == ')')) 
            {
                tmp += str[i];
                if(str[i] == '(') score++;
                if(str[i] == ')') score--;
                continue;
            }
            if(str[i] == '(') 
            {
                dfs(i + 1, score, _l + 1, _r, tmp);
                ++score;
            }
            else if(str[i] == ')')
            {
                dfs(i + 1, score, _l, _r + 1, tmp);
                --score;
            }
            tmp += str[i];
        }

        if(score >= 0) dfs(str.size(), score, _l, _r, tmp);
    }

public:
    vector<string> removeInvalidParentheses(string s) {

        str = s;
        l = 0; r = 0;
        for(auto c : s)
        {
            if(c == '(') 
            {
                ++l;
            }
            else if(c == ')') 
            {
                if(l == 0) ++r;
                else --l;
            }
        }

        dfs(0, 0, 0, 0, "");

        return ans;
    }
};

Solution s;

int main()
{
    s.removeInvalidParentheses(")(()c))(");
    return 0;
}