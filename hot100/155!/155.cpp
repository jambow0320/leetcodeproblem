// 最小栈，要求设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 很容易想到在栈push的时候push两个元素，一个是原元素，一个是当前的最小值
// 当然也可以更加优化，维护一个当前的最小值，push的时候只push一个偏移量，即val - NowMin，注意这里的NowMin是上一次的最小值，还不包含val
// 这样的话，如果偏移量小于0，说明当前的val是最新的最小值，在处理pop和top的时候注意一下就行
// pop的时候可以通过这个判断重置最小值，top的时候也得再判断下，是返回偏移量+NowMin还是直接返回NowMin
// 注意相减的int溢出


#include <algorithm>
#include <stack>

using std::stack;

class MinStack
{
public:
    MinStack() : NowMin(__INT_MAX__) {}

    void push(int val)
    {
        long long diff = (long long)val - NowMin;
        sta.push(diff);
        NowMin = std::min(NowMin, val);
    }

    void pop()
    {
        long long diff = sta.top();
        if(diff < 0) NowMin = NowMin - diff;
        sta.pop();
    }

    int top()
    {
        long long diff = sta.top();
        if(diff < 0) return NowMin;
        else return sta.top() + NowMin;
    }

    int getMin()
    {
        return NowMin;
    }

private:
    int NowMin;
    stack<long long> sta;
};