// 最长递增子序列
// nlogn的做法是维护一个当前的最长上升子序列(当然，并不是当前真正的，是一个保持部分未来状态的)
// 每次进来一个新元素如果比末尾要大，就把他插入末尾，如果没有，说明他可以替换之前的某一个
// 这个替换可能会觉得有点奇怪，但是你把他想成未来的某种未实现的状态，为未来做准备
// 二分找到这个位置插进去就行了
/*
以输入序列 [0,8,4,12,2] 为例：

第一步插入 0，d=[0]；

第二步插入 8，d=[0,8]；

第三步插入 4，d=[0,4]；

第四步插入 12，d=[0,4,12]；

第五步插入 2，d=[0,2,12]。

*/

#include <vector>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int len = 0;
        vector<int> d;
        d.push_back(nums[0]);

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > d[len])
            {
                d.push_back(nums[i]);
                ++len;
            }
            else
            {
                int l = 0, r = len, pos = -1;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(d[mid] < nums[i])
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }

        return len + 1;
    }
};