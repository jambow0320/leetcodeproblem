#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int now = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i])
            {
                swap(nums[i], nums[now++]);
            }
        }
        return ;
    }
};