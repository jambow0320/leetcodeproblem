/*
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/

/*
很容易想到维护单调栈，去存每个位置的高度，但是对于当前位置，怎么找到最优的left是个问题
干脆对于每个位置先不去找最优的left，假设这个位置的height是x，它紧接着后面的位置入栈的height是y
那么如果y>x，那么x都不用去找left，因为他的left给y用肯定更大
如果y<x，那么这个时候x就会有存在一些特殊的left位置，y用不了，也就是height处于y到x之间的位置，
这部分可能产生的答案是需要及时更新的，更新完了之后x就没有意义了，也可以丢掉
那这些位置怎么遍历呢，实际上就是出栈的时候弹出的元素，在维护单调栈的时候顺便更新答案了
在最后再加入一个height为0的特殊列，主动把栈里的元素都清一遍，以得到最右端为界的矩形面积
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

        vector<int> height(cols + 1);

        int ans = 0;
        for (int i = 0; i < rows; ++i)
        {
            vector<int> sta;
            for (int j = 0; j <= cols; ++j)
            {
                if (j == cols || matrix[i][j] == '0')
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