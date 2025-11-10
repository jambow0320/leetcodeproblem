#include <vector>

using std::vector;

class Solution {
private:
    int binary_search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] <= target) { ans = mid; l = mid + 1; }
            else r = mid - 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = binary_search(nums, target - 1);
        ans[1] = binary_search(nums, target);
        ans[0]++;
        if(ans[0] != nums.size() && nums[ans[0]] != target)
        {
            ans[0] = -1;
            ans[1] = -1;
        }
        else if(ans[0] == -1 || ans[1] == -1 || ans[0] == nums.size()) 
        { 
            ans[0] = -1;
            ans[1] = -1;
        }
        return ans;
    }
};