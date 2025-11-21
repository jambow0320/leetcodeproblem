#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> tag(n + 1);
        for(int i = 0; i < n; ++i)
        {
            if(i) tag[i] += tag[i - 1];
            if(i == 0 || tag[i] > 0)
            {
                if(i == n - 1) return true;
                ++tag[i];
                if(i + nums[i] + 1 < n) --tag[i + nums[i] + 1];
            }
        }
        
        return false;
    }
};