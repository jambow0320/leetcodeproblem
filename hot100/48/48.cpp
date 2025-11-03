#include <vector>
#include <utility>

using std::vector; 
using std::pair;
using std::make_pair;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i <= n / 2; ++i) // 层数
        {
            pair<int, int> rot[4];
            rot[0] = make_pair(i, i);
            rot[1] = make_pair(n - i - 1, i);
            rot[2] = make_pair(n - i - 1, n - i - 1);
            rot[3] = make_pair(i, n - i - 1);

            int len = n - 2 * (i);
            for(int j = 0; j < len - 1; ++j)
            {
             
                for(int k = 0; k < 3; ++k)
                {
                    std::swap(matrix[rot[k].first][rot[k].second], 
                        matrix[rot[k + 1].first][rot[k+1].second]);
                
                }
                
                ++rot[0].second;
                --rot[1].first;
                --rot[2].second;
                ++rot[3].first;
            }
        }
    }
};