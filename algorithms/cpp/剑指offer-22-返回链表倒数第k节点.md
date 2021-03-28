

# 倒数第 k 个元素的问题

设有两个指针 p 和 q，初始时均指向头结点。首先，先让 p 沿着 next 移动 k 次。此时，p 指向第 k+1个结点，q 指向头节点，两个指针的距离为 k 。然后，同时移动 p 和 q，直到 p 指向空，此时 q 即指向倒数第 k 个结点。可以参考下图来理解：

 

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

