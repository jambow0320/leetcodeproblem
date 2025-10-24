// 注意dp(sum + 1)，不要dp(sum)

#include <vector>

using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; ++i)
            sum += nums[i];
        if(sum & 1) return false;
        sum /= 2;

        vector<bool> dp(sum + 1);
        dp[0] = true;
    
        for(int i = 0; i < n; ++i)
        {
            int val = nums[i];
            for(int j = sum; j >= val; --j)
                if(dp[j - val]) dp[j] = true;
        }

        return dp[sum];
    }
};