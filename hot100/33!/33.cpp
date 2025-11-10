/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/

/*
我的想法是二分找到这个奇异点，也就是从这个点+1开始的往后都递增，前面则是旋转过去的一段，然后把数组分为两个部分再去找
实际做的时候有很多细节，首先这个奇异点可能不存在，比如数组[1]，那这时候就是负数，和size()做比较的时候一定要注意，不要让一个负数和size_t做比较，你+1让它变成0再比
其次在二分找这个点的时候，对于ans的赋值要判断一些，因为对于[9 1 5]这样的数组
先判断(9, 1, 5) mid=1的时候，然后发现符合，就往左走
这个时候是(9)，对于单独的它肯定也成立，所以这个时候要判断一下
*/

/*
题解则是一遍二分找到，实际也挺好想，两边区间总有一个是完全有序的，然后可以找这个有序的范围，如果在里面就往里跳，如果不在就往旁边走
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    int find_rev(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] <= nums[r]) 
            { 
                if(nums[mid] <= nums[nums.size() - 1])
                    ans = mid; 
                r = mid - 1; 
            }
            else l = mid + 1;
        }
        return ans;
    }

public:
    int search(vector<int>& nums, int target) {
        int revpos = find_rev(nums);
        --revpos;
        if(revpos + 1 >= 0 && revpos + 1 < nums.size() && nums[revpos + 1] <= target && target <= nums[nums.size() - 1])
        {
            int k = std::lower_bound(nums.begin() + revpos + 1, nums.end(), target) - nums.begin();
            return nums[k] == target ? k : -1;
        }
        if(revpos >= 0 && nums[0] <= target && target <= nums[revpos])
        {
            int k = std::lower_bound(nums.begin(), nums.begin() + revpos, target) - nums.begin();
            return nums[k] == target ? k : -1;
        }
        return -1;
    }
};