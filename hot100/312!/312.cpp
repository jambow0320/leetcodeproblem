/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。
如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。
*/
// 顺着想不太好搞，因为戳气球会合并区间，这不是我们想要的，区间dp要尽量去分割区间做子问题
// 反着来去填气球就行了，令 solve(i,j) 表示将开区间 (i,j) 内的位置全部填满气球能够得到的最多硬币数。

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
private:
    vector<vector<int>> dp;
    vector<int> val;
    int dfs(int l, int r)
    {
        if(l + 1 == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        for(int i = l + 1; i <= r - 1; ++i)
           dp[l][r] = max(dp[l][r], dfs(l, i) + dfs(i, r) + val[i] * val[l] * val[r]);
        return dp[l][r];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        dp.resize(n + 2, vector<int>(n + 2, -1));

        val[0] = 1;val[n + 1] = 1;
        for(int i = 1; i <= n; ++i) val[i] = nums[i - 1];

        return dfs(0, n + 1);
    }
};