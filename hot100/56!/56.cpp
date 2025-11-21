/*
有别的做法，到时候想想
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> tag(20000 + 4);
        vector<vector<int>> ans;

        for(auto x : intervals)
        {
            ++tag[x[0] * 2];
            --tag[x[1] * 2 + 1];
        }

        int lst = -1;
        for(int i = 0; i <= 20001; ++i)
        {
            if(i) tag[i] += tag[i - 1];
            if(lst == -1)
            {
                if(tag[i] > 0) lst = i;
            }
            else
            {
                if(tag[i] == 0)
                {
                    ans.push_back(vector<int>{lst / 2, (i - 1) / 2});
                    lst = -1;
                }
            }
        }

        return ans;
    }
};