#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int now = nums[0];
        int cnt = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            if(now == nums[i]) ++cnt;
            else 
            {
                --cnt;
                if(cnt == -1)
                {
                    now = nums[i];
                    cnt = 1;
                }
            }
        }

        return now;
    }
};