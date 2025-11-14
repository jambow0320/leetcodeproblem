#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(256);

        int ptr = 0, ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            ++cnt[s[i]];
            while(cnt[s[i]] > 1)
            {
                --cnt[s[ptr]];
                ++ptr;
            }
            ans = std::max(ans, i - ptr + 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("pwwkew");
    return 0;
}