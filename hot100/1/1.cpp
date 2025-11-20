#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;

        for(int i = 0; i < nums.size(); ++i)
        {
            int other = target - nums[i];
            auto it = hash.find(other);
            if(it != hash.end())
            {
                ans.push_back(i);
                ans.push_back(it->second);
                return ans;
            }
            hash[nums[i]] = i;
        }

        return ans;
    }
};