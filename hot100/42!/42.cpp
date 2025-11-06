/*
容易想到的做法是维护一个前缀max和后缀max数组
然后对于每一个位置，它能接的水量是min(lmax,rmax)-height[now]
但这样的空间是O(N)的

由于我们只需要min(lmax,rmax)，我们可以维护两个指针从开头和结尾往中间扫，同时维护当前的lmax,rmax
只需要保证，lmax小于rmax时，更新左指针，那对于左指针它当前的min(lmax,rmax)=lmax
*/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        int lptr = 0, rptr = height.size() - 1;
        int lmax = -__INT_MAX__, rmax = -__INT_MAX__;
        int ans = 0;
        while(lptr <= rptr)
        {
            lmax = max(lmax, height[lptr]);
            rmax = max(rmax, height[rptr]);
            if(lmax < rmax)
            {
                ans += lmax - height[lptr];
                ++lptr;
            }
            else
            {
                ans += rmax - height[rptr];
                --rptr;
            }
        }
        return ans;
    }
};