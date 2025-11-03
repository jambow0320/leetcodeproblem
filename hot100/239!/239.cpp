/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/

// 只要思考清楚满足怎样约束条件的值可以扔掉，就能设计出相应的单调队列
// 在这个题里，如果位置比自己小，而且值比自己小，就可以丢掉
// 按照这个，设计一个单调减的双端队列即可

// 然后这个题按k分块，也可以做

#include <vector>
#include <deque>
#include <utility>

using std::vector;
using std::deque;
using std::pair;

class Solution {
private:
    void add(deque<pair<int, int>> &q, int val, int pos)
    {
        while(!q.empty())
        {
            pair<int, int> backnow = q.back();
            if(backnow.first <= val) q.pop_back();
            else break;
        }
        q.push_back(std::make_pair(val, pos));
    }

    void del(deque<pair<int, int>> &q, int pos)
    {
        if(pos >= q.front().second)
        {
            q.pop_front();
        }
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        for(int i = 0; i < k; ++i)
            add(q, nums[i], i);

        vector<int> ans;
        ans.push_back(q.front().first);
        for(int i = 1; i + k - 1 < nums.size(); ++i)
        {
            del(q, i - 1);
            add(q, nums[i + k - 1], i + k - 1);
            ans.push_back(q.front().first);
        }

        return ans;
    }
};