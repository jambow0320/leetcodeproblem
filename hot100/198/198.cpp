#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n = nums.size();
        vector<vector<int> > dp(n, vector<int>(2, 0));
        int ans = 0;

        for(int i = 0; i < n; ++i)
        {
            if(!i) dp[i][1] = nums[i];
            else
            {
                dp[i][1] = std::max(dp[i - 1][0] + nums[i], dp[i - 1][1]);
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            }

            ans = std::max(ans, dp[i][1]);
            ans = std::max(ans, dp[i][0]);
        }

        return ans;
    }
};