#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);

        int ans = 0;
        vector<int> sta;
        for (int j = 0; j < heights.size(); ++j)
            {
                while (!sta.empty())
                {
                    int toph = sta.back();

                    if (heights[toph] >= heights[j])
                    {
                        sta.pop_back();
                        int left = sta.empty() ? -1 : sta.back();
                        int width = j - left - 1;
                        ans = max(ans, heights[toph] * width);
                    }
                    else break;
                }

                sta.push_back(j);
            }
    }
};