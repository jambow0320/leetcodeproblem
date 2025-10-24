/*
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
让你对这个pair序列对排序，使得他们满足要求

考虑先把这些按身高排序，然后一个一个地插进最后的序列的空里
如果没有相同身高，那插入的时候很简单，你扫一遍，
前面有多少空就意味着最后会有多少个人在自己前面，你找到对应前面有ki个空位的空位插进去就可以了
如果有相同身高呢，那也先简单，先插入ki大的就行了
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });

        vector<vector<int>> ans(people.size());
        for (auto x : people)
        {
            int emptyplace = x[1];
            for (auto &i : ans)
            {
                if(emptyplace == 0 && i.empty())
                {
                    i = x;
                    break;
                }
                if(i.empty()) --emptyplace;
            }
        }

        return ans;
    }
};