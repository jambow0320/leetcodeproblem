/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/

// 从右上角开始贪心找，小于就往左，大于就往下
// 感觉主要是要从一个有选择的地方往下找，就比如你不能从左上角，因为他往哪个方向都是变大

#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = matrix[0].size() - 1;
        while(1)
        {
            int val = matrix[x][y];
            if(target == val) return true;
            if(target < val)
                --y;
            else ++x;
            if(y < 0 || x >= matrix.size())
                return false;
        }
    }
};