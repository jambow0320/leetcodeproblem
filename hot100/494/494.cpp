#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums) sum += x;

        if(abs(target) > sum) return 0;

        vector<vector<int>> dp(n + 1, (vector<int>(sum * 2 + 1, 0)));
        int bias = sum;
        dp[0][0 + bias] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = -sum; j <= sum; ++j)
                if(dp[i - 1][j + bias] != 0)
                {
                    dp[i][j + bias + nums[i - 1]] += dp[i - 1][j + bias];
                    dp[i][j + bias - nums[i - 1]] += dp[i - 1][j + bias];
                }
        
        return dp[n][target + bias];
    }
};