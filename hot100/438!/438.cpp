// 找到字符串中所有字母异位词
/*
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
*/

// 滑动窗口解决，只需要注意到异位词本质上是每个字母的计数相同即可

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();

        vector<int> cnt(26, 0);
        for(auto c : p) ++cnt[c - 'a'];
        int diff = 0;
        for(int i = 0; i < 26; ++i) if(cnt[i]) ++diff;

        if(n < m) return vector<int>();
        for(int i = 0; i < m; ++i)
        {
            if(cnt[s[i] - 'a'] == 0) ++diff;
            --cnt[s[i] - 'a'];
            if(cnt[s[i] - 'a'] == 0) --diff;
        }

        vector<int> ans;
        if(diff == 0) ans.push_back(0);

        for(int i = 1; i < n - m + 1; ++i)
        {
            if(cnt[s[i - 1] - 'a'] == 0) ++diff;
            ++cnt[s[i - 1] - 'a'];
            if(cnt[s[i - 1] - 'a'] == 0) --diff;

            if(cnt[s[i + m - 1] - 'a'] == 0) ++diff;
            --cnt[s[i + m - 1] - 'a'];
            if(cnt[s[i + m - 1] - 'a'] == 0) --diff;

            if(diff == 0) ans.push_back(i);
        }

        return ans;
    }
};