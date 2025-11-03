#include <cmath>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int x = sqrt(i);
            if(x * x == i) { dp[i] = 1; continue; }
            dp[i] = i;
            for(int j = 1; j <= x; ++j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};