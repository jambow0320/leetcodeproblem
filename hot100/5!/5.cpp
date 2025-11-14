/*
最长回文子串
*/

/*
很简单想到n^2dp
然后空间也能优化到O(1)，就是暴力马拉车，对于每个位置暴力往外扩就行
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));

        string ans;
        for(int len = 1; len <= s.size(); ++len)
        {
            for(int i = 0; i + len - 1 < s.size(); ++i)
                if(s[i] == s[i + len - 1])
                {
                    if((len == 1 || len == 2) || dp[i + 1][i + len - 2] == 1)
                    {
                        dp[i][i + len - 1] = 1;
                        if(ans.size() != len)
                        {
                            ans = string(s.begin() + i, s.begin() + i + len);
                        }
                    }
                }
        }

        return ans;
    }
};