// 注意边界，也就是aa这种长度为2的

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int length = s.size();
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        // for(int i = 0; i < length; ++i) { dp[i][i] = true; dp[i + 1][i] = true;

        int ans = 0;
        for (int sublen = 1; sublen <= length; ++sublen)
            for (int i = 0; i + sublen <= length; ++i)
            {
                if (s[i] == s[i + sublen - 1])
                {
                    if (sublen <= 2 || dp[i + 1][i + sublen - 2])
                    {
                        dp[i][i + sublen - 1] = true;
                        ++ans;
                    }
                }
            }

        return ans;
    }
};