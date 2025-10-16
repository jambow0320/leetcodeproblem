#include <bits/stdc++.h>

using namespace std;

/*
空间复杂度O(1)判断回文链表
先快慢指针找到链表中心点和结尾点
然后把链表中心之后的翻转一下
再两边同时往中间扫判断
最后再翻转回去即可
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        if(!head -> next) return true;
        if(!(head -> next) -> next) 
        {
            if(head->next->val == head->val) return true;
            else return false;
        }
        fast = fast -> next;
        bool odd = 0;
        while(1)
        {
            slow = slow -> next;
            fast = fast -> next;
            if(!fast -> next)
            {
                odd = true;
                break;
            }
            else fast = fast -> next;
            if(!fast -> next) break;
        }

        ListNode *mid = slow, *ed = fast;
        if(odd) rev(mid, NULL);
        else rev(mid->next, NULL);

        ListNode *l = head, *r = ed;
        bool fg = false;
        while(1)
        {
            if(l->val != r->val) break;
            if(l == mid) { fg = true; break; }
            l = l -> next;
            r = r -> next;
        }
    
        rev(ed, NULL);
        return fg;
    }

private:
    void rev(ListNode *u, ListNode *lst)
    {
        static ListNode *tmp;
        tmp = u->next;
        u->next = lst;
        if(tmp) rev(tmp, u);
    }
};