#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int sum = 0;
        int pre_min = 0;
        int ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if(i == 0) ans = sum;
            else ans = max(ans, sum - pre_min);

            pre_min = min(pre_min, sum);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    return 0;
}