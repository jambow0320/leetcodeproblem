#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
            for(auto x : coins)
                if(i - x >= 0 && dp[i - x] != -1)
                {
                    if(dp[i] == -1) dp[i] = dp[i - x] + 1;
                    else dp[i] = min(dp[i - x] + 1, dp[i]);
                }
        return dp[amount];
    }
};