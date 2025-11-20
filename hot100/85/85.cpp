/*
[['0','0','1','0'],
 ['0','0','1','0'],
 ['0','0','1','0'],
 ['0','0','1','1'],
 ['0",'1','1','1'],
 ['0",'1','1','1'],
 ['1",'1','1','1']]
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols);

        int ans = 0;
        for (int i = 0; i < rows; ++i)
        {
            vector<int> sta;
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    ++height[j];

                while (!sta.empty())
                {
                    int toph = sta.back();

                    if (height[toph] >= height[j])
                    {
                        sta.pop_back();
                        int left = sta.empty() ? -1 : sta.back();
                        int width = j - left - 1;
                        ans = max(ans, height[toph] * width);
                    }
                    else break;
                }

                if(sta.size() >= 1)
                    ans = max(ans, (j - sta.back()) * height[j]);
                else
                    ans = max(ans, height[j] * (j + 1));

                sta.push_back(j);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {
    {'0','0','0','0','0','0','1'},
    {'0','0','0','0','1','1','1'},
    {'1','1','1','1','1','1','1'},
    {'0','0','0','1','1','1','1'}
    };

    s.maximalRectangle(matrix);

    return 0;
}