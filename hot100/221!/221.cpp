// 简单dp，总之二维的东西涉嫌最优化就考虑dp

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int> > dp(m, vector<int>(n, 0) );

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if(i && j)
                    {
                        int up = dp[i - 1][j];
                        int left = dp[i][j - 1];
                        if(up == left)
                        {
                            if(matrix[i - up][j - left] == '1')
                                dp[i][j] = up + 1;
                            else dp[i][j] = up;
                        }
                        else 
                        {
                            dp[i][j] = std::min(up, left) + 1;
                        }
                    }
                    ans = std::max(dp[i][j], ans);
                }
            }

        /*
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
                std::cout << dp[i][j] << ' ';
            std::cout << std::endl;
        }*/
            
        
        return ans * ans;
    }
};

int main()
{
    return 0;
}