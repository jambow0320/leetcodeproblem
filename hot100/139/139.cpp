#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictset;
        for(auto word : wordDict)
            wordDictset.insert(word);

        size_t length = s.size();
        vector<bool> dp(length + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= length; ++i)
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] && (wordDictset.count(s.substr(j, i - j))))
                {
                    dp[i] = true;
                    break;
                }
            }

        return dp[length];
    }
};