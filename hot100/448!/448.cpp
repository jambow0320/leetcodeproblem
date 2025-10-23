// 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
// 请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
// O(1)额外空间
// 简单的使用hash表是O(n)额外空间的
// 我们把nums本身当作hash表就行，如果一个值x存在，就把nums[x]+=n来打标记
// 由于nums[x]都<=n，要求实际值的时候就%n就行了

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int x = (nums[i] - 1) % n;
            if(nums[x] <= n) 
                nums[x] += n;
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if(nums[i] <= n) ans.push_back(i + 1);
        return ans;
    }
};

Solution s;

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> ans = s.findDisappearedNumbers(nums);
    return 0;
}