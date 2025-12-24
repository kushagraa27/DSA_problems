// problem: 876. Middle of the Linked List
// diffiulty: easy
// topic: linked list, two pointers, weekly contest 95
// approach: initialise 2 pointers, fast and slow, as head then iterate the slow ptr by one node step by step and fast ptr iterates by 2, when fast ptr reaches at last node or NULL
// then the pos of slow ptr is the middle of linked list
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL &&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    }
};
