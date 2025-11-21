#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 2), suffix(n + 2);
        prefix[0] = -INT_MAX;
        suffix[n + 1] = INT_MAX;
        for(int i = 1; i <= n; ++i) prefix[i] = max(prefix[i - 1], nums[i - 1]);
        for(int i = n; i >= 1; --i) suffix[i] = min(suffix[i + 1], nums[i - 1]);

        int l = 0, r = n + 1;
        for(int i = 1; i <= n; ++i)
        {
            int now = nums[i - 1];
            if(i > 1)
            {
                if(now < nums[i - 2]) break;
            }

            if(suffix[i + 1] < now) break;
            l = i;
        }

        for(int i = n; i >= 1; --i)
        {
            int now = nums[i - 1];
            if(i < n)
            {
                if(now > nums[i]) break;
            }
            
            if(prefix[i - 1] > now) break;
            r = i;
        }

        if(l < r) return r - l - 1;
        else return 0;
    }
};