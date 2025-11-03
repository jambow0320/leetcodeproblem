/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

要求O(1)额外空间，且不能修改原数组
*/

// 如果可以修改原数组，那就可以原地hash
/*
不行的话，就得想别的方法

方法一：二分
二分一个值，然后for一遍，找比这个值小于等于的个数
只有过了重复值那个点之后的，才会有变动，不然<=v的个数就是<=v个
nlogn

方法二：链表找环
把i和nums[i]建边(0号点可以认为是dummyhead，因为我们有n+1个点吗，就是0-n)
问题转变为找链表的环头，用快慢指针去做就好了
*/

#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};