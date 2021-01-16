[link]https://leetcode.com/problems/linked-list-cycle/#/description  

141. Linked List Cycle  

Given a linked list, determine if it has a cycle in it.  


Follow up:  

Can you solve it without using extra space?  

  
Seen this question in a real interview before?  

[solution]  
链表是否带环，可以采用快慢指针法，用两个指针指向链表的头结点，一个指针一次向后走一个位置，另一个指针向后走两个位置，这样如果两个指针如果相遇，这样就能说该链表带环，如果当快指针或者快指针的next为NULL时，还没有相遇。哪么就说明该链表不带环。
