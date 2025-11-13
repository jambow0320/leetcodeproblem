/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

// 排序之后，枚举前两个数，然后第三个数也不用hash，你就从后往前维护一个指针一直扫就行了
// 对于麻烦的有数相同的情况，比如[-1,-1,2]，[0, 0, 0]
// 可以这样搞，让x不能等于上次的x，让y不能等于上次的y，自然对应的z也不会等于上次的z，就不会算重了

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::pair;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> s;
        vector<vector<int>> ans;
        for(auto x : nums)
            ++s[x];
        vector<pair<int, int>> uniquenums(s.begin(), s.end());
        std::sort(uniquenums.begin(), uniquenums.end());

        for(int i = 0; i < uniquenums.size(); ++i)
        {
            for(int j = i; j < uniquenums.size(); ++j)
            {
                if(i == j && uniquenums[i].second <= 1) continue;

                int x = uniquenums[i].first, y = uniquenums[j].first;
                int z = 0 - x - y;
                if(z >= y)
                {
                    if(s[z] != 0)
                    {
                        if(y == z)
                        {
                            if(uniquenums[j].second <= 1) continue;
                            if(x == y && uniquenums[i].second <= 2) continue;
                            ans.push_back(vector<int>{x, y, z});
                        }
                    }
                }
            }
        }

        return ans;
    }
};