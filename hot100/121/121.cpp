#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, future_max = 0;
        for(int i = prices.size() - 1; i >= 0; --i)
        {
            if(future_max > prices[i])
                ans = std::max(future_max - prices[i], ans);
            future_max = std::max(future_max, prices[i]);
        }
        return ans;
    }
};