// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 一开始只想到基于排序的方法，或者是基于并查集在hash权重域上合并的方法
// 后来发现对于一段连续权值序列，我们只需要找他的头就可以了，也就是x-1不存在的情况，他就是一段区间的头，然后往后一直扫就行
// 需要注意后面找头的时候需要遍历的是set，而不是原数组不然复杂度不对


#include <vector>
#include <algorithm>
#include <unordered_set>

using std::vector;
using std::max;
using std::unordered_set;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> num_set;
        for(auto x : nums)
            num_set.insert(x);

        int ans = 0;
        for(auto x : num_set)
            if(!num_set.count(x - 1))
            {
                int len = 1;
                int now = x;
                while(1)
                {
                    if(!num_set.count(++now))
                        break;
                    ++len;
                }
                ans = max(len, ans);
            }

        return ans;
    }
};