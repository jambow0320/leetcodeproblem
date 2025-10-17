#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = -__INT_MAX__;
        vector<vector<int> > dp(n, vector<int>(2));

        dp[0][0] = dp[0][1] = nums[0];
        ans = nums[0];
        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = std::min(std::min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);
            dp[i][1] = std::max(std::max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);
            ans = std::max(ans, dp[i][1]);
        }

        return ans;
    }
};