/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/

/*
如果只有一个数组，那直接返回nums[k]就可以了

有两个数组的话，对于要求kth，找到nums1[k/2 - 1]，nums2[k/2 - 1]
如果nums1[k/2]小于nums2[k/2]，那就说明对于nums1[0...k/2 - 1]这k/2个元素
他们一定是小于真正的kth的，可以把这nums1这前k/2个元素扔掉，那k就变成k/2了，迭代继续

感觉思想就是不断排除掉k/2个(这k/2也没必要是当前k/2小的，只要能保证他们在k前面)，然后递归找
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
private:
    int find_kth(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();
        int bias1 = 0, bias2 = 0;
        while(1)
        {
            if(bias1 == n) return nums2[k + bias2 - 1];
            if(bias2 == m) return nums1[k + bias1 - 1];
            if(k == 1) return std::min(nums1[bias1], nums2[bias2]);

            int pivot1 = k / 2 + bias1 - 1;
            int pivot2 = k / 2 + bias2 - 1;

            pivot1 = std::min(pivot1, n - 1);
            pivot2 = std::min(pivot2, m - 1);

            if(nums1[pivot1] < nums2[pivot2])
            {
                k -= pivot1 - bias1 + 1;
                bias1 = pivot1 + 1;
            }
            else
            {
                k -= pivot2 - bias2 + 1;
                bias2 = pivot2 + 1;
            }
        }
    }

public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(((n + m) & 1) == 1)
        {
            int k = (n + m) / 2 + 1;
            return find_kth(nums1, nums2, k);
        }
        else
        {
            int k = (n + m) / 2;
            return (find_kth(nums1, nums2, k) + find_kth(nums1, nums2, k + 1)) / 2.;
        }
    }
};

#include <iostream>
using namespace std;

int main()
{
    Solution s;
    cout << s.findMedianSortedArrays({1, 2}, {3, 4}) << endl;
    return 0;
}