#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int pos, vector<int> now, const vector<int> &nums, vector<vector<int>> &ans)
    {
        if(pos == nums.size())
        {
            ans.push_back(now);
            return ;
        }

        dfs(pos + 1, now, nums, ans);
        now.push_back(nums[pos]);
        dfs(pos + 1, now, nums, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(0, vector<int>(), nums, ans);
        return ans;
    }
};