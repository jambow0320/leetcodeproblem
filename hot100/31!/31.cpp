/*
实现next_permutation
*/

/*
手玩一下排列就会发现，生成下一个排列实际上
是找到一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
同时，这个[较小数]一定要尽量靠右，在交换完之后，还需要对他后面的东西从小到大排序
可以看下面的例子，我们交换的是5和6
*/

/*
xooxoooo
58764321
68754321
61234578
*/

/*
不难发现，这个最靠右的[较小值]，他的后面一定是一段上升序列，其实我们也不用排序，直接reverse就可以了
从后往前扫，扫到不上升了就是[较小值]，然后再扫一遍，找到[较大值]，swap一下再reverse
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        int pos = n - 1;
        for(pos = n - 1; pos >= 0; --pos)
        {
            if(pos == 0 || nums[pos] > nums[pos - 1]) break;
        }

        if(pos == 0) { reverse(nums.begin(), nums.end()); return ; }

        for(int i = n - 1; i >= pos; --i)
            if(nums[pos - 1] < nums[i])
            {
                std::swap(nums[pos - 1], nums[i]);
                break;
            }
        std::reverse(nums.begin() + pos, nums.end());
    }
};