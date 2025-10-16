// 用快排的思想去找第k大    
// 需要注意全为相同值的特殊情况，小心卡成n^2的
// 为了处理这个情况，我们的判断条件变为<=和>=也交换，而不是<和>才交换
// 这样能让i、j尽量同时往中间靠，就会二分着缩小长度，而不是pivot每次都是在头和尾

#include <vector>
#include <random>

using std::vector;

class Solution {
private:
    std::mt19937 gen;

    int getInt(int a, int b)
    {
        std::uniform_int_distribution<> dist(a, b);
        return dist(gen);
    }

    int partition(vector<int>& seq, int l, int r)
    {
        int pivot_pos = getInt(l, r);
        int pivot = seq[pivot_pos];
        std::swap(seq[pivot_pos], seq[l]);

        int i = l + 1, j = r;
        while(1)
        {
            while(i <= j && seq[i] < pivot) ++i;
            while(i <= j && seq[j] > pivot) --j;
            if(i >= j) break;
            std::swap(seq[i], seq[j]);
            ++i; --j;
        }

        std::swap(seq[l], seq[j]);

        return j;
    }


public:
    Solution() : gen(std::random_device{}()) {}

    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = n - k + 1;
        int l = 0, r = n - 1;
        while(1)
        {
            int pos = partition(nums, l, r);
            if(pos == k) return nums[pos];
            else if(pos < k) l = pos + 1;
            else r = pos - 1;
        }
    }

};

int main() {}