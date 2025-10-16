#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ans = nullptr;

        ListNode *tmpa = headA;
        int cnta = 0, cntb = 0;
        while (1)
        {
            if(tmpa->next != nullptr) tmpa = tmpa->next;
            else break;
            ++cnta;
        }
    
        ListNode *tmpb = headB;
        while(1)
        {
            if(tmpb->next != nullptr) tmpb = tmpb->next;
            else break;
            ++cntb;
        }

        if(tmpb == tmpa)
        {
            if(cnta < cntb) { swap(headA, headB); swap(cnta, cntb); }
            while(cnta > cntb)
            {
                headA = headA->next;
                --cnta;
            }
            while(headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            ans = headA;
        }

        return ans;
    }
};

int main() { return 0; }