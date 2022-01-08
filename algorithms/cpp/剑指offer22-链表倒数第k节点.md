## 输出链表中倒数第 k 个结点
https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/


思路 ：设置两个指针，快指针先走（k-1）步，然后快慢再一起走，当快指针走到最后时，慢指针指向就为倒数第k个数。
```c++
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head, *slow = head;
        while(k--) {
            if(fast == nullptr) return nullptr;
            fast = fast->next;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```
