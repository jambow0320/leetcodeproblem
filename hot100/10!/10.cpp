/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。

*/

/*
只要想到用dp做就好做了
对于匹配带*这种，也很容易找到连续累加的dp方式
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
private:
    bool equal(char a, char b)
    {
        if(a == '.') return true;
        return a == b;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 2, vector<bool>(s.size() + 2, 0));

        dp[0][0] = 1;
        int now = 0;
        for(int i = 0; i < p.size(); ++i)
        {
            ++now;
            if(i + 1 < p.size() && p[i + 1] == '*')
            {
                char c = p[i];
                ++i;
                for(int j = 0; j <= s.size(); ++j) dp[now][j] = dp[now - 1][j];
                for(int j = 0; j < s.size(); ++j)
                    if(equal(c, s[j]))
                    {
                        if(j != 0 && (s[j] == s[j - 1] || c == '.')) 
                            dp[now][j + 1] = dp[now][j + 1] | dp[now][j];
                        dp[now][j + 1] = dp[now][j + 1] | dp[now - 1][j];
                    }
            }
            else
            {
                char c = p[i];
                for(int j = 0; j < s.size(); ++j)
                    if(equal(c, s[j]))
                        dp[now][j + 1] = dp[now][j + 1] | dp[now - 1][j];
            }
        }

        return dp[now][s.size()];
    }
};

int main()
{
    Solution s;
    s.isMatch("abcd", "d*");
    return 0;
}