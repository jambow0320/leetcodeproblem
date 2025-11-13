/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。
*/

/*
这个和42有点类似

容易想到，左右各维护一个单调栈，左边是单调递增的，右边是单调递减的

然后维护两个指针，一起往中间扫，只要保证先动小的那边的指针，其实就是在轮流遍历这两个单调栈
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while(l < r)
        {
            int area = std::min(height[l], height[r]) * (r - l);
            ans = std::max(ans, area);
            if(height[l] <= height[r]) ++l;
            else --r;
        }

        return ans;
    }
};