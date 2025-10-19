// 判断一个链表里是否有环，并且要返回环的起始节点，要求O(1)空间不用哈希
// 具体实现是快慢指针，碰到一起后，再开一个ptr从头开始，和slow一起开始跑，相遇的节点就是环起始节点
// 推导可以从快慢指针相遇的时候计算他们走了多少步，有个两倍的关系，可以推导出一些东西

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode *slow = head, *fast = head;

        while(fast)
        {
            slow = slow->next;
            if(!fast->next) return nullptr;

            fast = fast->next->next;
            if(slow == fast)
            {
                ListNode *ptr = head;
                while(ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        
        return nullptr;
    }
};