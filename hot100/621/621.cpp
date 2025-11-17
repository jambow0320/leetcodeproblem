#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ++n;
        int ans = 0;
        vector<int> cnt(26);
        for(auto x : tasks)
            ++cnt[x - 'A'];
        int tot = tasks.size();

        sort(cnt.begin(), cnt.end());
        while(1)
        {
            int slot = n;
            for(int i = 25; i >= 0; --i)
                if(cnt[i]) 
                {
                    --slot;
                    --cnt[i];
                    --tot;
                    if(!slot) break;
                }
                else break;
            
            if(tot == 0) {
                ans += n - slot;
                return ans;
            }
            else
            {
                ans += n;
            }

            sort(cnt.begin(), cnt.end());
        }
    }
};