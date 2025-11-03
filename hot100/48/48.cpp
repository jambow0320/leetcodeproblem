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

            cout << rot[0].first << ' ' << rot[0].second << endl;
            cout << rot[1].first << ' ' << rot[1].second << endl;
            cout << rot[2].first << ' ' << rot[2].second << endl;
            cout << rot[3].first << ' ' << rot[3].second << endl;
            cout << "---------" << endl;

            int len = n - 2 * (i + 1);
            for(int j = 0; j <= len / 2; ++j)
            {
                for(int k = 0; k < 3; ++k)
                {
                    std::swap(matrix[rot[k].first][rot[k].second], 
                        matrix[rot[k + 1].first][rot[k].second]);
                
                }
                
                ++rot[0].second;
                --rot[1].first;
                --rot[2].second;
                ++rot[3].first;
            }
        }
    }
};