#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size());

        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            pre[i] = pre[i - 1] + nums[i];

        std::unordered_map<int, int> cnt;
        int ans = 0;
        ++cnt[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            ans += cnt[pre[i] - k];
            ++cnt[pre[i]];
        }
        return ans;
    }
};